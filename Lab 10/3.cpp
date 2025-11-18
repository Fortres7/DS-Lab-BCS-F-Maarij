#include <iostream>
using namespace std;


void Heapify_up_Max(int *arr, int index)
  {
    while (index != 0 && arr[index] > arr[(index - 1) / 2])
    {
      swap(arr[index], arr[(index - 1) / 2]);
      index = (index - 1) / 2;
    }
  }
void insertMax(int *arr, int size, int val)
  {
    arr[size] = val;
    Heapify_up_Max(arr, size);
    size++;
  }


int main()
{
  int arr[] = {1, 23, 12, 9, 30, 2, 50};
  int n = 7;
  int k;
  cout << "Enter K: ";
  cin >> k;

  for (int i = 0; i < k; i++)
  {
    insertMax(arr, i, arr[i]);
  }

  cout << arr[0];

  return 0;
}
