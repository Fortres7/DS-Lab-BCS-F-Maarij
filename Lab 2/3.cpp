#include <iostream>
using namespace std;

int main()
{

  int students;
  cout << "How many students data you want to store?: ";
  cin >> students;
  int **arr = new int *[students];
  int courses[99];

  for (int i = 0; i < students; i++)
  {
    cout << "Enter number of courses of student#" << i + 1 << ": ";
    cin >> courses[i];
    arr[i] = new int[courses[i]];
  }

  for (int i = 0; i < students; i++)
  {
    cout << "Enter " << courses[i] << " Course Marks for Student#" << i + 1 << ":\n";
    for (int j = 0; j < courses[i]; j++)
    {
      cout << "Enter Marks#" << j + 1 << ":";
      cin >> arr[i][j];
    }
  }

  cout << "\nStudents Data:\n";
  for (int i = 0; i < students; i++)
  {
    cout << "Student#" << i + 1 << ": ";
    double sum = 0;
    for (int j = 0; j < courses[i]; j++)
    {
      cout << arr[i][j] << " ";
      sum += arr[i][j];
    }
    double average = sum / courses[i];
    cout << "Average: " << average << endl;
  }

  for (int i = 0; i < students; i++)
  {
    delete[] arr[i];
  }
  delete[] arr;

  return 0;
}
