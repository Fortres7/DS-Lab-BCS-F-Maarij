#include <iostream>
using namespace std;

class Runners
{

public:
  string name;
  int time;

  Runners()
  {
    this->name = "";
    this->time = 0;
  }
  Runners(string name, int time)
  {
    this->name = name;
    this->time = time;
  }
};

void merge(Runners arr[], int left, int mid, int right)
{
  int n1 = mid - left + 1;
  int n2 = right - mid;

  Runners L[n1], R[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[left + i];
  for (int j = 0; j < n2; j++)
    R[j] = arr[mid + 1 + j];

  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2)
  {
    if (L[i].time <= R[j].time)
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(Runners arr[], int left, int right)
{
  if (left < right)
  {
    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
  }
}

int main()
{
  int n = 10;
  Runners *R = new Runners[n];

  for (int i = 0; i < n; i++)
  {
    string a;
    int b;
    cout << "Enter name and finish time for runner " << i + 1 << ":\n";
    cin >> a;
    cin >> b;
    R[i].name = a;
    R[i].time = b;
  }

  mergeSort(R, 0, n - 1);

  int m = 5;
  Runners *R2 = new Runners[m];

  for (int i = 0; i < m; i++)
  {
    R2[i] = R[i];
  }
  delete[] R;

  cout << "Top 5 fastest runners: \n";
  for (int i = 0; i < 5; i++)
  {
    cout << i + 1 << ". " << R2[i].name << " - " << R2[i].time << " seconds";
    cout << endl;
  }

  delete[] R2;
  return 0;
}
