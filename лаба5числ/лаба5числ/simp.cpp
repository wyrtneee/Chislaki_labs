//
//  simp.cpp
//  5
//
//  Created by Ксения Герасименя on 16.11.23.
//

#include "simp.hpp"
#include <iostream>
#include <cmath>

using namespace std;

double f31(double x, double y)
{
    return pow(x,2)+2*y;
}


double simpson_method( double(&f31)(double, double), double a1, double b1, double c1, double d1, int n1, int m1)
{
    double hx = (b1 - a1) / (2 * n1);
    double hy = (d1 - c1) / (2 * m1);
    double result = 0.0;
    for (int i = 0; i <= n1 - 1; ++i) {
        for (int j = 0; j <= m1 - 1; ++j)
        {
            result += f31(a1 + (i * 2) * hx, c1 + (j * 2) * hy);
            
            result += 4 * f31(a1 + (i * 2 + 1) * hx, c1 + (j * 2) * hy);
            
            result +=f31(a1 + (i * 2 + 2) * hx,c1 + (j * 2) * hy);
            
            result += 4 * f31(a1 + (i * 2) * hx, c1 + (j * 2 + 1) * hy);
            
            result += 16 *f31(a1 + (i * 2 + 1) * hx, c1 + (j * 2 + 1) * hy);
            
            result += 4 * f31(a1 + (i * 2 + 2) * hx, c1 + (j * 2 + 1) * hy);
            
            result += f31(a1 + (i * 2) * hx,c1 + (j * 2 + 2) * hy);
            
            result += 4 * f31(a1 + (i * 2 + 1) * hx, c1 + (j * 2 + 2) * hy);
            
            result += f31(a1 + (i * 2 + 2) * hx, c1 + (j * 2 + 2) * hy);
        }
    }
    return hx * hy * result / 9;
}

double calculate_simpson( double a1, double b1, double c1, double d1,  int n1,  int m1)
{
   
    double intg1 = 0;
    double intg2 = simpson_method( f31,a1, b1, c1, d1, n1, m1);

    while (abs(intg1 - intg2) > 15 * 1e-7) {
        n1 *= 2;
        intg1 = intg2;
        intg2 = simpson_method( f31,a1, b1, c1, d1, n1, m1);

    }
  
    return intg2;
}

