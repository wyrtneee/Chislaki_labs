#include <iostream>
#include <cmath>

using namespace std;

double f(double x);
double MT(double a, double b, double h, int n, double h2, int n2);
double MS(double a, double b, double h, int n, double h2, int n2);


double MS(double a, double b, double h, int n, double h2, int n2)
{
    double sum; double sum2;

    do {
        sum = f(a);
        double x = a;
        x = x + h;

        sum2 = f(a);
        double x2 = a;
        x2 = x2 + h2;

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

        for (int i = 0; i < (n2 / 2); i++)
        {
            sum2 = sum2 + (4 * f(x2));
            x2 = x2 + 2 * h2;
        }

        x2 = a + 2 * h2;

        for (int i = 0; i < (n2 / 2) - 1; i++)
        {
            sum2 = sum2 + (2 * f(x2));
            x2 = x2 + 2 * h2;
        }

        sum2 = sum2 + f(b);
        sum2 = sum2 * h2 / 3;

        n = n * 2;
        n2 = n * 2;
        h = (b - a) / n;
        h2 = h / 2;


    } while (abs(sum2 - sum) / 15 > 1e-7);
    cout << n << endl;

    return sum;
}

double MT(double a, double b, double h, int n, double h2, int n2)
{
    double sum;
    double sum2;

    do
    {
        double x = a;
        sum = f(x);
        x = x + h;

        double x2 = a;
        sum2 = f(x2);
        x2 = x2 + h2;

        for (int i = 0; i < n - 1; i++)
        {
            sum = sum + 2 * f(x);
            x = x + h;
        }

        for (int i = 0; i < n2 - 1; i++)
        {
            sum2 = sum2 + 2 * f(x2);
            x2 = x2 + h2;
        }

        sum = sum + f(x);
        sum = (h * sum) / 2;

        sum2 = sum2 + f(x2);
        sum2 = (h2 * sum2) / 2;

        n = n * 2;
        n2 = n * 2;
        h = (b - a) / n;
        h2 = h / 2;

    

    } while (abs(sum2 - sum) / 3 > 1e-7);
    cout << n << endl;

    return sum;
}

double f(double x)
{
    return sqrt(x+pow(x,3));
}


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
   

    I1 = MT(a, b, h, n, h2, n2);

    cout << "Интеграл методом трапеции " << I1 << endl;

    I2 = MS(a, b, h, n, h2, n2);

    cout << "Интеграл методом Симсона " << I2 << endl;
    
}
