#include <iostream>
#include <vector>
#include <iomanip>
#include <assert.h>


using namespace std;

void get_matrix(vector<vector<double>> matrix, int size)
{
}
void print(const vector<vector<double>>& matrix, int m, int n)
//void print(vector<vector<double>> &matrix, int m, int n)
{
  for (int i = 0;i < m;i++)
  {
    for (int j = 0;j < n;j++)
    {
      cout <<setw(10) << matrix[i][j] << ' ';

    }

    cout << endl;
  }
}



//vector<vector<double>> Gauss_method(vector<vector<double>> matrix, int m, int n, int k)
void Gauss_method(vector<vector<double>>& matrix,vector<vector<double>>& matrix1, int m, int n, int k)
{
  
  double max_coef= 1;
  int index=0;
  for (int i = k;i < m;i++)
  {
    if (max_coef <= matrix[i][k])
    {
      index = i;
      max_coef = matrix[i][k];
    }
  }
  if (index != 0)
  {
    swap(matrix[k], matrix[index]);
    
    print(matrix, 3, 4);
  }
  cout << endl;
  for (int i = k;i < m;i++)
  {
    double del = matrix[i][k];
    for (int j = k;j < n;j++)
    {
      matrix[i][j]=matrix[i][j] / del;
    }
    
    
  }
  
  

  for (int i = m-1;i > k;i--)
    for (int j = k;j<n;j++)
  {
    matrix[i][j] = matrix[i][j] - matrix[k][j];
  }

  print(matrix, 3, 4);
  cout << endl;
  k++;
  if (k != m)
  {
    Gauss_method(matrix,matrix1, 3, 4, k);
    
  }
  
  else
  {


    

    double x3 = matrix[m - 1][n - 1] / matrix[m - 1][n - 2];
    //result.push_back(x3);
    double x2 = (matrix[m- 2][n - 1] - x3* (matrix[m - 2][n - 2])) / matrix[m - 2][n - 3];
    //result.push_back(x2);
    double x1 = (matrix[m - 3][n - 1] - x2* matrix[m - 3][n - 3]- x3 * (matrix[m - 3][n - 2])) / matrix[m - 3][n - 4];
    //result.push_back(x3);
    cout << x1 << ' ' << x2 << ' ' << x3 << endl;
      double x4 = x1* matrix1[m-3][n-4] + x2* matrix1[m-3][n-3] + x3* matrix1[m-3][n-2];
      double x5 = x1* matrix1[m-2][n-4] + x2* matrix1[m-2][n-3] + x3* matrix1[m-2][n-2];
      double x6 = x1* matrix1[m-1][n-4] + x2* matrix1[m-1][n-3] + x3*matrix1[m-1][n-2];
      
      cout << x5 << ' ' << x4 << ' ' << x6 << endl;
      
      double x7 = matrix1[m-3][n-1] - x4;
      double x8 = matrix1[m-2][n-1] - x5;
      double x9 = matrix1[m-1][n-1] - x6;
      cout<< x7 <<' ' << x8 << ' ' << x9 << endl;
  }
  k++;
  //return matrix;
    
   
    
}



int main()
{
  vector<vector<double>> matrix
{
    {2.3, 5.7, -0.8, -6.49},
      {3.5, -2.7, 5.3, 19.2},
    {1.7, 2.3, -1.8, -5.09 }
  };
    vector<vector<double>> matrix1
  {
      {2.3, 5.7, -0.8, -6.49},
        {3.5, -2.7, 5.3, 19.2},
      {1.7, 2.3, -1.8, -5.09 }
    };
    
  for (int i = 0;i < 3;i++) {
    assert(!(matrix[i][i] == 0));
  }
    Gauss_method(matrix,matrix1, 3,4,0);
    return 0;
}
