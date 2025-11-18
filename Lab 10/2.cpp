#include <iostream>
using namespace std;

class Heap
{

public:
  int arr[100];
  int size;

  Heap()
  {
    size = 0;
    for (int i = 0; i < 100; i++)
    {
      arr[i] = 0;
    }
  }

  void insertMax(int val)
  {
    if (size == 100)
    {
      cout << "Heap OverFlow!\n";
      return;
    }
    arr[size] = val;
    Heapify_up_Max(size);
    size++;
  }

  void Heapify_up_Max(int index)
  {
    while (index != 0 && arr[index] > arr[(index - 1) / 2])
    {
      swap(arr[index], arr[(index - 1) / 2]);
      index = (index - 1) / 2;
    }
  }

  void Heapify_down_Max(int index)
  {
    int largest = index;
    int left = (2 * index) + 1;
    int right = (2 * index) + 2;

    if (left < size && arr[left] > arr[largest])
    {
      largest = left;
    }
    if (right < size && arr[right] > arr[largest])
    {
      largest = right;
    }
    if (largest != index)
    {
      swap(arr[index], arr[largest]);
      Heapify_down_Max(largest);
    }
  }

  void delete_Max()
  {
    if (size == 0)
    {
      cout << "Heap underflow!\n";
      return;
    }
    cout << "Deleted element: " << arr[0] << endl;
    arr[0] = arr[size - 1];
    size--;
    Heapify_down_Max(0);
  }

  void print()
  {
    for (int i = 0; i < size; i++)
    {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
};

bool isHeap(int *arr, int n)
{

  for (int i = 0; i <= (n - 2) / 2; i++)
  {

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[i] < arr[left])
    {
      return false;
    }
    if (right < n && arr[i] < arr[right])
    {
      return false;
    }
  }
  return true;
}
void heapify(int arr[], int n, int i)
{
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest])
    largest = left;

  if (right < n && arr[right] > arr[largest])
    largest = right;

  if (largest != i)
  {
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}

void HeapSort(int arr[], int n)
{
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  for (int i = n - 1; i >= 1; i--)
  {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}

int main()
{

  cout << "Original Array: \n";
  Heap Heap;
  int array[] = {8, 7, 6, 5, 4};
  int n = 5;
  for (int i = 0; i < 5; i++)
  {
    Heap.insertMax(array[i]);
  }
  Heap.print();

  if (isHeap(array, n))
  {
    cout << "It represents a Max Heap\n";
  }
  else
  {
    cout << "It doesnt represents a Heap\n";
  }

  cout << "After Heap sort\n";
  HeapSort(array, n);
  for (int i = 0; i < n; i++)
  {
    cout << array[i] << " ";
  }

  return 0;
}
