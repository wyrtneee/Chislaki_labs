//
//  lab5.cpp
//  5
//
//  Created by Ксения Герасименя on 14.11.23.
//

#include "lab5.hpp"
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
