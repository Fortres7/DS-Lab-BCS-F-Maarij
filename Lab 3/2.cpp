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

void merge(Node *&tail1, Node *&head2){  
  tail1->next = head2;
}

void Sort(Node *&head){
  Node *temp1 = head;
  Node *temp2 = head;

  while (temp1 != NULL)
  {
    while (temp2 != NULL)
    {
      if (temp1->data < temp2->data)
      {
        int X = temp1->data;
        temp1->data = temp2->data;
        temp2->data = X;
      }
      temp2 = temp2->next;
    }
    temp2 = head;
    temp1 = temp1->next;
  }  
}
int main()
{

  cout << "Enter number of elements for List A: ";
  int n;
  cin >> n;
  int num;

  cout << "Enter element#1: ";
  cin >> num;
  Node *node1 = new Node(num);
  Node *head1 = node1;
  Node *tail1 = node1;
  for (int i = 1; i < n; i++)
  {
    cout << "Enter element#" << i + 1 << ": ";
    cin >> num;
    insertAtTail(tail1, num);
  }

  cout << "Enter number of elements for List B: ";
  cin >> n;

  cout << "Enter element#1: ";
  cin >> num;
  Node *node2 = new Node(num);
  Node *head2 = node2;
  Node *tail2 = node2;
  for (int i = 1; i < n; i++)
  {
    cout << "Enter element#" << i + 1 << ": ";
    cin >> num;
    insertAtTail(tail2, num);
  }
  cout <<endl;
  cout << "List A: ";
  print(head1);
  cout << "List B: ";
  print(head2);
  cout <<endl;
  Sort(head1);
  cout << "Sorted List A: ";
  print(head1);
  Sort(head2);
  cout << "Sorted List B: ";
  print(head2);

  merge(tail1, head2);
  cout <<endl;
  cout << "Merged List: ";
  print(head1);

  Sort(head1);
  cout <<endl;
  cout << "Sorted Merged List: ";
  print(head1);

  return 0;
}




