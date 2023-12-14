#include <iostream>
#include <math.h>
#include <iomanip>
#include <vector>
#include "functions.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    double x1, x2;
    vector<double> answer(2);
    x1 = 0.5;
    x2 = 0.2;
    answer = Newton_method(x1, x2, 2, 0);
    cout << endl;
    cout << "ŒÚ‚ÂÚ: ";
    print(answer, 2);
    cout << endl;

    answer = Newton_method(x1, x2, 2, 0.01);
    cout << endl;
    cout << "ŒÚ‚ÂÚ: ";
    print(answer, 2);
    cout << endl;

    answer = Newton_method(x1, x2, 2, 0.05);
    cout << endl;
    cout << "ŒÚ‚ÂÚ: ";
    print(answer, 2);
    cout << endl;

    answer = Newton_method(x1, x2, 2, 0.1);
    cout << endl;
    cout << "ŒÚ‚ÂÚ: ";
    print(answer, 2);
    cout << endl;
}
