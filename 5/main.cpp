#include <iostream>
#include <cmath>
#include "method_trap+cimpsona.hpp"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    srand((unsigned)time(NULL));

    int n1= 2 * (rand() % 100 + 1);
    int m1 = 2 * (rand() % 100 + 1);

   
    int a1 = 0;
    int b1 =2;
    int c1 = 0;
    int d1 = 1;
    double I3;
    
    int n = 2;
        int n2 = n * 2;
        double a = 0.6;
        double b = 1.724;
        double h = (b - a) / n;
        double h2 = (b - a) / n2;
        double I1;
        double I2;


        I1 = FindMetodTrap(a, b, h, n, h2, n2);

        cout << "Интеграл методом трапеции " << I1 << endl;

        I2 = FindMetodSimpsona(a, b, h, n);

        cout << "Интеграл методом Симсона " << I2 << endl;


    I3 = FindSumSimps2(a1, b1, c1, d1, n1,m1);

    cout << "Интеграл методом Симпсона2 " <<endl<< I3 << endl;
    
    
    
    
}
