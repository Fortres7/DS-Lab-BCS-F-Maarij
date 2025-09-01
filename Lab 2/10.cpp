#include <iostream>
using namespace std;

int main()
{
  int Category;
  cout << "Enter number of categories to store : ";
  cin >> Category;

  int *Booknum = new int[Category];
  int **books = new int *[Category];

  for (int i = 0; i < Category; i++)
  {
    cout << "Enter number of books in Category " << i + 1 << ": ";
    cin >> Booknum[i];

    books[i] = new int[Booknum[i]];

    for (int j = 0; j < Booknum[i]; j++)
    {
      cout << "Enter Book ID for Category " << i + 1
           << ", Book " << j + 1 << ": ";
      cin >> books[i][j];
    }
  }

  int SID;
  cout << "Enter Book ID to search: ";
  cin >> SID;

  bool found = false;

  for (int i = 0; i < Category; i++)
  {
    for (int j = 0; j < Booknum[i]; j++)
    {
      if (books[i][j] == SID)
      {
        cout << "Book ID " << SID << " found in Category " << i + 1 << endl;
        found = true;
      }
    }
  }
  if (!found)
  {
    cout << "Book ID " << SID << " not found." << endl;
  }

  for (int i = 0; i < Category; i++)
  {

    delete[] books[i];
  }

  delete[] books;

  delete[] Booknum;
}
