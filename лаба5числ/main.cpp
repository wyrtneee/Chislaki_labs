#include <iostream>
#include <cmath>
#include "lab5.hpp"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int n = 2;
    int n2 = n * 2;
    double a = 0.6;
    double b = 1.724;
    double h = (b - a) / n;
    double h2 = (b - a) / n2;
    double I1;
    double I2;


    I1 = MetodTrap(a, b, h, n, h2, n2);

    cout << "Интеграл методом трапеции " << I1 << endl;

    I2 = MetodSimpsona(a, b, h, n, h2, n2);

    cout << "Интеграл методом Симсона " << I2 << endl;

}
