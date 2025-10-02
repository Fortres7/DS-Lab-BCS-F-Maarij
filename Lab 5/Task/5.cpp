#include <iostream>
using namespace std;

bool isSafe(int **arr, int n, int row, int col, int val)
{
  for (int i = 0; i < n; i++)
  {
    if (arr[row][i] == val)
    {
      return false;
    }
    if (arr[i][col] == val)
    {
      return false;
    }
    if (arr[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val) //Formula to check each 3x3 grids 
    {
      return false;
    }
  }
  return true;
}

bool solve(int **arr, int n)
{
  for (int row = 0; row < n; row++)
  {
    for (int col = 0; col < n; col++)
    {
      if (arr[row][col] == 0)
      {
        for (int val = 1; val <= 9; val++)
        {
          if (isSafe(arr, n, row, col, val))
          {
            arr[row][col] = val;
            bool FurtherSolPossible = solve(arr, n);
            if (FurtherSolPossible)
            {
              return true;
            }
            else
            {
              arr[row][col] = 0;
            }
          }
        }
        return false;
      }
    }
  }
  return true;
}

int main()
{

  int n = 9;

  int **Grid = new int *[n];
  for (int i = 0; i < n; i++)
  {
    Grid[i] = new int[n];
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      Grid[i][j] = 0;
    }
  }

  cout << "Enter numbers for 9x9 grid: " << endl;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      int value;
      do
      {
        cout << "Enter At Position[" << i << "][" << j << "]: ";
        cin >> value;
        if (value < 0 || value > 9)
          cout << "Enter a number between 0 and 9.\n";
      } while (value < 0 || value > 9);
      Grid[i][j] = value;
    }
  }

  cout << endl;
  cout << "Original Grid: ";
  cout << endl;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << Grid[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  if (!solve(Grid, n))
  {
    cout << "The Grid is not possible to solve";
  }
  else
  {
    cout << "Solved Soduko Grid:";
    cout << endl;
  
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cout << Grid[i][j] << " ";
      }
      cout << endl;
    }
  }

  return 0;
}
