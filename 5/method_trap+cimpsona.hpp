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


double F(double x);
double FindMetodTrap(double a, double b, double h, int n, double h2, int n2);
double FindMetodSimpsona(double a, double b, double h, int n, double h2, int n2);
double FindSumSimps(double a, double b, double h, int n);
double FindSumTrap(double a, double b, double h, int n);
double FindMetodSimpsona2( double(&f31)(double, double), double a1, double b1, double c1, double d1, int n1, int m1);
double FindSumSimps2( double a1, double b1, double c1, double d1,  int n1,  int m1);
double F31(double x, double y);

