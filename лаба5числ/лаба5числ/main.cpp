#include <iostream>
#include <cmath>
#include "simp.hpp"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int n1=10;
    int m1 = n1 / 2;
   
    int a1 = 0;
    int b1 =2;
    int c1 = 0;
    int d1 = 1;
    double I3;
    


    I3 = calculate_simpson(a1, b1, c1, d1, n1,m1);

    cout << "Интеграл методом Симпсона2 " <<endl<< I3 << endl;
    
    
    
    
}
