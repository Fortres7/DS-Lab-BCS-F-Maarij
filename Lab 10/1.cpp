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

  void insertMin(int val)
  {
    if (size == 100)
    {
      cout << "Heap OverFlow!\n";
      return;
    }
    arr[size] = val;
    Heapify_up_Min(size);
    size++;
  }

  void update_key_Max(int i, int new_val)
  {
    int val = arr[i];
    arr[i] = new_val;
    cout << "Updated Element " << val << " To " << new_val << endl;
    if (new_val > val)
    {
      Heapify_up_Max(i);
    }
    else
    {
      Heapify_down_Max(i);
    }
  }

  void update_key_Min(int i, int new_val)
  {
    int val = arr[i];
    arr[i] = new_val;
    cout << "Updated Element " << val << " To " << new_val << endl;
    if (new_val < val)
    {
      Heapify_up_Min(i);
    }
    else
    {
      Heapify_down_Min(i);
    }
  }

  void Heapify_up_Max(int index)
  {
    while (index != 0 && arr[index] > arr[(index - 1) / 2])
    {
      swap(arr[index], arr[(index - 1) / 2]);
      index = (index - 1) / 2;
    }
  }

  void Heapify_up_Min(int index)
  {
    while (index != 0 && arr[index] < arr[(index - 1) / 2])
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

  void Heapify_down_Min(int index)
  {
    int smallest = index;
    int left = (2 * index) + 1;
    int right = (2 * index) + 2;

    if (left < size && arr[left] < arr[smallest])
    {
      smallest = left;
    }
    if (right < size && arr[right] < arr[smallest])
    {
      smallest = right;
    }
    if (smallest != index)
    {
      swap(arr[index], arr[smallest]);
      Heapify_down_Min(smallest);
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

  void delete_Min()
  {
    if (size == 0)
    {
      cout << "Heap underflow!\n";
      return;
    }
    cout << "Deleted element: " << arr[0] << endl;
    arr[0] = arr[size - 1];
    size--;
    Heapify_down_Min(0);
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

int main()
{

  Heap MaxHeap;
  cout << "\nMax Heap: " << endl;
  MaxHeap.insertMax(8);
  MaxHeap.insertMax(7);
  MaxHeap.insertMax(6);
  MaxHeap.insertMax(5);
  MaxHeap.insertMax(4);
  MaxHeap.print();
  MaxHeap.update_key_Max(2, 9);
  MaxHeap.print();
  MaxHeap.delete_Max();
  MaxHeap.print();

  Heap MinHeap;
  cout << "\nMin Heap: " << endl;
  MinHeap.insertMin(8);
  MinHeap.insertMin(7);
  MinHeap.insertMin(6);
  MinHeap.insertMin(5);
  MinHeap.insertMin(4);
  MinHeap.print();
  MinHeap.update_key_Min(2, 9);
  MinHeap.print();
  MinHeap.delete_Min();
  MinHeap.print();

  return 0;
}
