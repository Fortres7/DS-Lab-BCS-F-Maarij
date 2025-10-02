#include <iostream>
using namespace std;

bool isSafe(int **board, int row, int col, int n)
{
  for (int j = 0; j < n; j++)
    if (board[row][j] == 1)
      return false;

  for (int i = 0; i < n; i++)
    if (board[i][col] == 1)
      return false;

  for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    if (board[i][j] == 1)
      return false;

  for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    if (board[i][j] == 1)
      return false;

  return true;
}

void printBoard(int **board, int n, int &count)
{
  cout <<endl;
  cout << "Solution " << ++count << ":" <<endl;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cout << board[i][j] << " ";
    cout << endl;
  }
}

void SolvenQueens(int **board, int row, int n, int &count)
{
  if (row == n)
  {
    printBoard(board, n, count);
    return;
  }

  for (int j = 0; j < n; j++)
  {
    if (isSafe(board, row, j, n))
    {
      board[row][j] = 1;
      SolvenQueens(board, row + 1, n, count);
      board[row][j] = 0;
    }
  }
}

int main()
{
  int n;
  cout << "Enter N: ";
  cin >> n;

  int **Board = new int *[n];
  for (int i = 0; i < n; i++)
  {
    Board[i] = new int[n];
    for (int j = 0; j < n; j++)
      Board[i][j] = 0;
  }

  int count = 0;
  SolvenQueens(Board, 0, n, count);

  if (count == 0)
    cout << "No solution exists for N = " << n << endl;
  else
    cout << "Total solutions = " << count << endl;

  for (int i = 0; i < n; i++)
    delete[] Board[i];
  delete[] Board;

  return 0;
}
