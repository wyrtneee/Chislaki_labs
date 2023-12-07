//
//  functions.hpp
//  laba2k
//
//  Created by Ксения Герасименя on 7.12.23.
//

#ifndef functions_hpp
#define functions_hpp
#include <vector>
#include <stdio.h>
using namespace std;
#endif /* functions_hpp */


double f1(double x1, double x2);
//double df11(double x1, double x2);
double df11(double x1, double x2);
//double df12(double x1, double x2);
double df12(double x1, double x2);
//double df21(double x1, double x2);
double df21(double x1, double x2);
//double df22(double x1, double x2);
double df22(double x1, double x2);
void print(const vector<vector<double>>& matrix, int m, int n);
void print(const vector<double>& matrix, int m);
vector<vector<double>> J( double x1, double x2);
vector<double>  otric_vector(double x1, double x2);
vector<double> Gauss_method(vector<vector<double>>& matrix1, int m, int n, int k);
vector<double> Newton_method(double x1, double x2, int n);
