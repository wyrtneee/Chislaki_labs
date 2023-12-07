#include <iostream>
#include <math.h>
#include <iomanip>
#include <vector>
#include "functions.hpp"
using namespace std;

                int main()
                {
                    setlocale(LC_ALL, "ru");
                    double x1, x2;
                    vector<double> answer(2);
                    x1 = 0.5;
                    x2 = 0.2;
                  answer=Newton_method(x1, x2, 2);
                  cout << endl;
                  cout << "Ответ: ";
                  print(answer, 2);

                }
