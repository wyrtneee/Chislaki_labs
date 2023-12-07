//
//  functions.cpp
//  laba2k
//
//  Created by Ксения Герасименя on 7.12.23.
//

#include "functions.hpp"
#include <iostream>
#include <math.h>
#include <iomanip>
#include <vector>

using namespace std;

double f1(double x1, double x2)
{
  return (x1 * x1 * x1 + x2 * x2 * x2 - 6 * x1 + 3);
}
double f2(double x1, double x2)
{
  return (x1 * x1 * x1 - x2 * x2 * x2 - 6 * x2 + 2);
}
//double df11(double x1, double x2)
//{
//  return (f1(x1 + M * x1, x2) - f1(x1, x2)) / (M * x1);
//
//}
double df11(double x1, double x2)
{
    return (3*x1*x1-6);
}
//double df12(double x1, double x2)
//{
//  return ((f1(x1, x2 + M * x2) - f1(x1, x2)) / (M * x2));
//}
double df12(double x1, double x2)
{
    return (3*x2*x2);
}
//double df21(double x1, double x2)
//{
//  return ((f2(x1 + M * x1, x2) - f2(x1, x2)) / (M * x1));
//}
double df21(double x1, double x2)
{
    return (3*x1*x1);
}
//double df22(double x1, double x2)
//{
//  return ((f2(x1, x2 + M * x2) - f2(x1, x2)) / (M * x2));
//}
double df22(double x1, double x2)
{
    return ( ( - 3) * x2 * x2-6);
}



void print(const vector<vector<double>>& matrix, int m, int n)
{
    for (int i = 0;i < m;i++)
    {
        for (int j = 0;j < n;j++)
        {
            cout << setw(10) << matrix[i][j] << ' ';

        }

        cout << endl;
    }
}
void print(const vector<double>& matrix, int m)
{
    for (int i = 0;i < m;i++)
    {

        cout << setw(10) << matrix[i] << ' ';


    }
}



vector<vector<double>> J( double x1, double x2)
{
 vector<vector<double>> a(2, vector<double>(2));
    a[0][0] = df11(x1, x2);
    a[0][1] = df12(x1, x2);
    a[1][0] = df21(x1, x2);
    a[1][1] = df22(x1, x2);
    return a;
}
vector<double>  otric_vector(double x1, double x2)
{
    vector<double> F(2);
    F[0] = (-1)*  f1(x1, x2);
    F[1] = (-1)*f2(x1, x2);
    return F;
}

vector<double> Gauss_method(vector<vector<double>>& matrix1, int m, int n, int k)
{
    

        if (matrix1[1][1]==0||matrix1[0][0]==0)
        {
            cout << "На главной диагонали 0, делить нельзя" << endl;
            system("pause");
            exit(0);

        }
    

    if (k <= m)
    {
        double max_coef = 1;
        int index = 0;
        for (int i = k;i < m;i++)
        {
            if (max_coef <= abs(matrix1[i][k]))
            {
                index = i;
                max_coef = abs(matrix1[i][k]);
            }
        }
        if (index != 0)
        {
            swap(matrix1[k], matrix1[index]);


        }
       
        for (int i = k;i < m;i++)
        {
            double del = matrix1[i][k];
            for (int j = k;j < n;j++)
            {
                matrix1[i][j] = matrix1[i][j] / del;
            }


        }



        for (int i = m - 1;i > k;i--)
            for (int j = k;j < n;j++)
            {
                matrix1[i][j] = matrix1[i][j] - matrix1[k][j];
            }

       
      
        k++;
        if (k != m)
        {
            Gauss_method(matrix1, 2, 3, k);

        }

        k++;

    }
    vector<double> matrix2(2,0.0);
    for (int i = 0;i < 2;i++)
    {
        matrix2[i] = matrix1[i][n-1];
    }
    return matrix2;
}

vector<double> Newton_method(double x1, double x2, int n)
{
    
    const double eps = 1e-9;
    const double M = 0.001;
    const int NIT = 110;
    vector<double> delta(2, 0.0);
    vector<double> answer(2,0.0);
    vector<double> extr_vec;
    vector<vector<double>> syst(n, vector<double>(n + 1, 0.0));
    double delta1,delta2;
    vector<vector<double>> Jak(2, vector<double>(n));
    int k = 1;
    cout << setw(10) << "x1" << setw(10) << "x2" << setw(18) << "delta1" << setw(10) << "delta2" << setw(9) << "k" << endl;

    do
    {
        cout << endl;
        Jak = J(x1, x2);
       
        extr_vec = otric_vector(x1, x2);
       
        for (int i = 0;i < n;i++)
        {
            for (int j = 0;j < n;j++)
            {
                syst[i][j] = Jak[i][j];
                            }
                            syst[i][n] = extr_vec[i];
                        }
                      
                        delta = Gauss_method(syst, 2, 3, 0);
                        for (int i = 0; i < n; i++)
                        {
                            answer[i] += delta[i];
                        }
                       
                        double max1 = 0;
                        double max2 = 0;
                        for (int i = 0; i < n; i++)
                        {
                            if (abs(extr_vec[i]) > max1)
                                max1 = abs(extr_vec[i]);

                            if (abs(answer[i]) < 1)
                            {
                                if (abs(delta[i]) > max2)
                                    max2 = abs(delta[i]);
                            }
                            if (abs(delta[i] >= 1))
                            {
                                if (abs(delta[i] / answer[i]) > max2)
                                    max2 = abs(delta[i]);
                            }
                        }
                       
                        delta1 = max1;
                        delta2 = max2;
                       
                        x1 = answer[0];
                        x2 = answer[1];
                        for (int i = 0; i < n; i++)
                        {
                            cout << setw(10) << answer[i] << "   ";
                        }
                     
                        cout << setw(12) << delta1 << "   " << setw(3) << delta2 << "   " << setw(3) << k;
                        cout << endl;

                        k++;
                        if (k >= NIT)
                        {
                            cout << "\n   IER = 2 \n";
                            return vector<double>();
                            break;
                        }
                       /* cout << "X1 AND X2" << endl;
                        print(answer, 2);
                        cout << endl;*/
                    }
                    while (delta1 > eps || delta2 > eps);

                return answer;
                }
                    






