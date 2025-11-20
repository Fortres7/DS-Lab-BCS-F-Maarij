#include <iostream>
using namespace std;

class Student
{

public:
  Student *next;
  string name;
  int score;

  Student()
  {
    this->next = NULL;
    name = "";
    score = 0;
  }

  Student(string name, int score)
  {
    this->next = NULL;
    this->name = name;
    this->score = score;
  }
};

void addNode(Student *&head, string name, int score)
{
  Student *newStud = new Student(name, score);
  if (head == NULL)
  {
    head = newStud;
    return;
  }
  Student *temp = head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = newStud;
}

struct Node
{
  string name;
  int data;
  Node *next;
  Node(string name, int val)
  {
    this->name = name;
    data = val;
    next = NULL;
  }
};

void insertBucket(Node *&head, string n, int val)
{
  Node *newNode = new Node(n, val);
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

void RadixSort(Student arr[], int n)
{
  int exp = 1;

  Node *buckets[10];

  while (100 / exp > 0)
  {
    for (int i = 0; i < 10; i++)
    {
      buckets[i] = NULL;
    }

    for (int i = 0; i < n; i++)
    {
      int digit = (arr[i].score / exp) % 10;
      insertBucket(buckets[digit], arr[i].name, arr[i].score);
    }

    int idx = 0;
    for (int i = 0; i < 10; i++)
    {
      Node *temp = buckets[i];
      while (temp != NULL)
      {
        arr[idx].name = temp->name;
        arr[idx++].score = temp->data;
        temp = temp->next;
      }
      clearBucket(buckets[i]);
    }
    exp *= 10;
  }
}

void printdata(Student *head)
{
  Student *temp = head;
  while (temp != NULL)
  {
    cout << temp->name << "\t";
    cout << temp->score << "\t\n";
    temp = temp->next;
  }
}

void CopyToArray(Student *head, Student arr[], int n)
{
  Student *temp = head;
  for (int i = 0; i < n; i++)
  {
    arr[i].name = temp->name;
    arr[i].score = temp->score;
    temp = temp->next;
  }
}

void CopyToList(Student *&head, Student arr[], int n)
{
  Student *temp = head;
  for (int i = 0; i < n; i++)
  {
    temp->name = arr[i].name;
    temp->score = arr[i].score;
    temp = temp->next;
  }
}

int getPos(Student *&head, string name, int score)
{
  int pos = 1;
  Student *temp = head;
  while (temp != NULL)
  {
    if ((temp->name == name && temp->score == score))
    {
      return pos;
    }
    temp = temp->next;
    pos++;
  }
  return -1;
}

void DeleteStd(Student *&head, string name, int score)
{
  int pos = getPos(head, name, score);
  if (pos == -1)
  {
    return;
  }

  if (pos == 1)
  {
    Student *temp = head;
    head = head->next;
    delete temp;
    return;
  }

  Student *prev = head;
  for (int i = 1; i < pos - 1; i++)
  {
    prev = prev->next;
  }

  Student *delNode = prev->next;
  prev->next = delNode->next;
  delete delNode;
}

bool BinarySearch(Student arr[], int n, string name, int score)
{
  int l = 0;
  int r = n - 1;
  while (l <= r)
  {
    int mid = l + (r - l) / 2;
    if (arr[mid].name == name && arr[mid].score == score)
    {
      return true;
    }
    else if (arr[mid].score < score)
    {
      l = mid + 1;
    }
    else
    {
      r = mid - 1;
    }
  }
  return false;
}

int main()
{
  int n = 5;
  Student *head = NULL;

  addNode(head, "Ayan", 90);
  addNode(head, "Zameer", 60);
  addNode(head, "Sara", 70);
  addNode(head, "Sohail", 30);
  addNode(head, "Ahmed", 20);

  Student array[n];
  CopyToArray(head, array, n);

  cout << endl;
  cout << "Student Data: \n";
  printdata(head);

  cout << "\nSorted Student Data:\n";
  RadixSort(array, n);

  CopyToList(head, array, n);
  printdata(head);
  cout << endl;

  cout << "Enter Student Name and Score to search: \n";
  string a;
  int b;
  cout << "Name: ";
  cin >> a;
  cout << "Score: ";
  cin >> b;

  if (BinarySearch(array, n, a, b))
  {
    DeleteStd(head, a, b);
    cout << "\nDeleted Student:\nName: " << a << "\nScore: " << b << endl;
    cout << "\nStudent Data: \n";
    printdata(head);
  }
  else
  {
    cout << "\nStudent not found\n";
  }

  return 0;
}
