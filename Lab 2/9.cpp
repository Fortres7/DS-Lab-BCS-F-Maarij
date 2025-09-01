#include <iostream>
using namespace std;

int main()
{

  int **arr;
  int nonzerocount = 0;
  int rows;
  int cols;

  cout << "Enter number of rows: ";
  cin >> rows;

  cout << "Enter number of columnss: ";
  cin >> cols;

  arr = new int *[rows];

  for (int i = 0; i < rows; i++)
  {
    arr[i] = new int[cols];
  }

  cout << "Enter Values for the Matrix." << endl;
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      cout << "Enter Value for (" << i << "," << j << "): ";
      cin >> arr[i][j];
      if (arr[i][j] != 0)
      {
        nonzerocount++;
      }
    }
  }

  int **Compressed = new int *[nonzerocount];
  for (int i = 0; i < nonzerocount; i++)
  {
    Compressed[i] = new int[3];
  }

  cout << "Normal Matrix:" << endl;

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      cout << " " << arr[i][j] << " ";
    }
    cout << endl;
  }

  int count = 0;
  cout << "Compressed Form: " << endl;

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {

      if (arr[i][j] != 0)
      {
        Compressed[count][0] = i;
        Compressed[count][1] = j;
        Compressed[count][2] = arr[i][j];
        count++;
      }
    }
  }

  for (int i = 0; i < nonzerocount; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout << " " << Compressed[i][j] << " ";
    }
    cout << endl;
  }

  for (int i = 0; i < rows; i++)
  {
    delete[] arr[i];
  }
  delete[] arr;

  for (int i = 0; i < nonzerocount; i++)
  {
    delete[] Compressed[i];
  }
  delete[] Compressed;
}
