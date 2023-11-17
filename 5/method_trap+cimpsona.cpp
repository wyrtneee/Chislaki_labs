//
//  method_trap+cimpsona.cpp
//  5
//
//  Created by Ксения Герасименя on 17.11.23.
//

#include "method_trap+cimpsona.hpp"
//
//  lab5.cpp
//  5
//
//  Created by Ксения Герасименя on 14.11.23.
//


#include <iostream>
#include <cmath>

using namespace std;
double MetodSimpsona(double a, double b, double h, int n, double h2, int n2)
{
    double sum; double sum2;

    do {
        sum = find_sum_simps(a, b, h, n);
        sum2 = find_sum_simps(a, b, h2, n2);
        n = n * 2;
        n2 = n * 2;
        h = (b - a) / n;
        h2 = h / 2;

    } while (abs(sum2 - sum) / 15 > 1e-7);
    cout << n << endl;

    return sum;
}

double MetodTrap(double a, double b, double h, int n, double h2, int n2)
{
    double sum;
    double sum2;

    do
    {
        sum = find_sum_trap(a, b, h,n);
        sum2 = find_sum_trap(a, b, h2, n2);

        n = n * 2;
        n2 = n2 * 2;
        h = (b - a) / n;
        h2 = h / 2;



    } while (abs(sum2 - sum) / 3 > 1e-7);
    cout << n << endl;

    return sum;
}

double f(double x)
{
    return sqrt(x + pow(x, 3));
}
double find_sum_simps(double a, double b,double h,int n)
{
    double sum;
    sum = f(a);
    double x = a;
    x = x + h;


    for (int i = 0; i < (n / 2); i++)
    {
        sum = sum + (4 * f(x));
        x = x + 2 * h;
    }

    x = a + 2 * h;

    for (int i = 0; i < (n / 2) - 1; i++)
    {
        sum = sum + (2 * f(x));
        x = x + 2 * h;
    }

    sum = sum + f(b);
    sum = sum * h / 3;
    return sum;
}
double find_sum_trap(double a, double b, double h, int n)
{
    double x = a;
    double sum = f(x);
    x = x + h;


    for (int i = 0; i < n - 1; i++)
    {
        sum = sum + 2 * f(x);
        x = x + h;
    }
    sum = sum + f(x);
    sum = (h * sum) / 2;
    return sum;

}


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

