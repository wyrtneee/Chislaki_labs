//
//  method_trap+cimpsona.hpp
//  5
//
//  Created by Ксения Герасименя on 17.11.23.
//

#ifndef method_trap_cimpsona_hpp
#define method_trap_cimpsona_hpp

#include <stdio.h>

#endif /* method_trap_cimpsona_hpp */


double f(double x);
double MetodTrap(double a, double b, double h, int n, double h2, int n2);
double MetodSimpsona(double a, double b, double h, int n, double h2, int n2);
double find_sum_simps(double a, double b, double h, int n);
double find_sum_trap(double a, double b, double h, int n);
double MetodSimpsona2( double(&f31)(double, double), double a1, double b1, double c1, double d1, int n1, int m1);
double find_sum_simps2( double a1, double b1, double c1, double d1,  int n1,  int m1);
double f31(double x, double y);

