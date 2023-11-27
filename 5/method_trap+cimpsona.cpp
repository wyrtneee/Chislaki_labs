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
double FindMetodSimpsona(double a, double b, double h, int n)
{
    double sum; double sum2;

    do {
        sum = FindSumSimps(a, b, h, n);
        sum2 = FindSumSimps(a, b, h / 2, 2 * n);
        n = n * 2;
        h = (b - a) / n;
       

    } while (abs(sum2 - sum) / 15 > 1e-7);
    cout << n << endl;

    return sum2;
}

double FindMetodTrap(double a, double b, double h, int n, double h2, int n2)
{
    double sum;
    double sum2;

    do
    {
        sum = FindSumTrap(a, b, h,n);
        sum2 = FindSumTrap(a, b, h2, n2);

        n = n * 2;
        n2 = n2 * 2;
        h = (b - a) / n;
        h2 = h / 2;



    } while (abs(sum2 - sum) / 3 > 1e-7);
    cout << n << endl;

    return sum;
}

double F(double x)
{
    return sqrt(x + pow(x, 3));
}
double FindSumSimps(double a, double b,double h,int n)
{
    double sum;
    sum = F(a);
    double x = a;
    x = x + h;


    for (int i = 0; i < (n / 2); i++)
    {
        sum = sum + (4 * F(x));
        x = x + 2 * h;
    }

    x = a + 2 * h;

    for (int i = 0; i < (n / 2) - 1; i++)
    {
        sum = sum + (2 * F(x));
        x = x + 2 * h;
    }

    sum = sum + F(b);
    sum = sum * h / 3;
    return sum;
}
double FindSumTrap(double a, double b, double h, int n)
{
    double x = a;
    double sum = F(x);
    x = x + h;


    for (int i = 0; i < n - 1; i++)
    {
        sum = sum + 2 * F(x);
        x = x + h;
    }
    sum = sum + F(x);
    sum = (h * sum) / 2;
    return sum;

}


double F31(double x, double y)
{
    return pow(x,2)+2*y;
}


double FindMetodSimpsona2( double(&F31)(double, double), double a1, double b1, double c1, double d1, int n1, int m1)
{
    double hx = (b1 - a1) / (2 * n1);
    double hy = (d1 - c1) / (2 * m1);
    double result = 0.0;
    for (int i = 0; i <= n1 - 1; ++i) {
        for (int j = 0; j <= m1 - 1; ++j)
        {
            result += F31(a1 + (i * 2) * hx, c1 + (j * 2) * hy);
            
            result += 4 * F31(a1 + (i * 2 + 1) * hx, c1 + (j * 2) * hy);
            
            result +=F31(a1 + (i * 2 + 2) * hx,c1 + (j * 2) * hy);
            
            result += 4 * F31(a1 + (i * 2) * hx, c1 + (j * 2 + 1) * hy);
            
            result += 16 *F31(a1 + (i * 2 + 1) * hx, c1 + (j * 2 + 1) * hy);
            
            result += 4 * F31(a1 + (i * 2 + 2) * hx, c1 + (j * 2 + 1) * hy);
            
            result += F31(a1 + (i * 2) * hx,c1 + (j * 2 + 2) * hy);
            
            result += 4 * F31(a1 + (i * 2 + 1) * hx, c1 + (j * 2 + 2) * hy);
            
            result += F31(a1 + (i * 2 + 2) * hx, c1 + (j * 2 + 2) * hy);
        }
    }
    return hx * hy * result / 9;
}

double FindSumSimps2( double a1, double b1, double c1, double d1,  int n1,  int m1)
{
   
 
    double intg2 = FindMetodSimpsona2( F31,a1, b1, c1, d1, n1, m1);
    return intg2;
}

