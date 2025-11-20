#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
  Node(int val)
  {
    data = val;
    next = NULL;
  }
};

void insertBucket(Node *&head, int val)
{
  Node *newNode = new Node(val);
  if (head == NULL)
  {
    head = newNode;
    return;
  }
  Node *temp = head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = newNode;
}

void clearBucket(Node *&head)
{
  Node *temp;
  while (head != NULL)
  {
    temp = head;
    head = head->next;
    delete temp;
  }
}

int getMax(int arr[], int n)
{
  int mx = arr[0];
  for (int i = 1; i < n; i++)
  {
    if (arr[i] > mx)
      mx = arr[i];
  }
  return mx;
}

void RadixSort(int arr[], int n)
{
  int maxNum = getMax(arr, n);
  int exp = 1;

  Node *buckets[10];

  while (maxNum / exp > 0)
  {
    for (int i = 0; i < 10; i++)
    {
      buckets[i] = NULL;
    }

    for (int i = 0; i < n; i++)
    {
      int digit = (arr[i] / exp) % 10;
      insertBucket(buckets[digit], arr[i]);
    }

    int idx = 0;
    for (int i = 0; i < 10; i++)
    {
      Node *temp = buckets[i];
      while (temp != NULL)
      {
        arr[idx++] = temp->data;
        temp = temp->next;
      }
      clearBucket(buckets[i]);
    }

    exp *= 10;
  }
}

void RadixSortDescending(int arr[], int n)
{
  RadixSort(arr, n);
  int s = 0;
  int e = n - 1;
  while (s < e)
  {
    int temp = arr[s];
    arr[s] = arr[e];
    arr[e] = temp;
    s++;
    e--;
  }
}

void printArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int main()
{
  int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "\nOriginal array: \n";
  printArray(arr, n);

  RadixSort(arr, n);

  cout << "\nSorted array Ascending: \n";
  printArray(arr, n);

  RadixSortDescending(arr, n);
  cout << "\nSorted array Descending:\n";
  printArray(arr, n);

  return 0;
}
