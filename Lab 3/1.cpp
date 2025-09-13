#include <iostream>
using namespace std;

class Node
{

public:
  int data;
  Node *next;

  Node(int data)
  {
    this->data = data;
    this->next = NULL;
  }
};

void insertAtTail(Node *&tail, int d)
{
  Node *temp = new Node(d);
  tail->next = temp;
  tail = temp;
}

void print(Node *&head)
{
  Node *temp = head;

  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

bool checkpalindrome(int arr[], int x){
  int start = 0;
  int end = x-1;
  while (start<=end)
  {
    if (arr[start]!=arr[end])
    {
      return 0;
    }
    start++;
    end--;    
  }
  return 1;  
}

bool ispalindrome(Node *&head, int arr[], int x){
  
    int i = 0;
    Node *temp = head;
    while (temp != NULL)
    {
      arr[i] = temp->data;
      temp = temp->next;
      i++;
    }    
    return checkpalindrome(arr, x); 
}

int main()
{

  cout << "Enter number of elements: ";
  int n;
  cin >> n;
  int num;

  if (n > 0)
  {
    cout << "Enter element#1: ";
    cin >> num;
    Node *node1 = new Node(num);
    Node *head = node1;
    Node *tail = node1;
    for (int i = 1; i < n; i++)
    {
      cout << "Enter element#" << i + 1 << ": ";
      cin >> num;
      insertAtTail(tail, num);
    }
    print(head);
    int *arr = new int[n];
    if (ispalindrome(head, arr, n))
    {
      cout << "True" <<endl;
    }
    else{
      cout << "False" << endl;
    }    
  }
  else{
    cout << "Enter atleast 1 element" << endl;
  }

  return 0;
}
