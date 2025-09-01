#include <iostream>
using namespace std;

class SafePointer
{
private:
  int *ptr;

public:
  SafePointer()
  {
    ptr = new int;
  }
  void setValue(int value)
  {

    *ptr = value;
  }

  int getValue()
  {
    return *ptr;
  }

  void release()
  {
    delete ptr;
    ptr = nullptr;
  }

  ~SafePointer()
  {

    if (ptr != nullptr)
    {
      delete ptr;
    }
  }
};

int main()
{

  int Students = 5;

  SafePointer *Marks = new SafePointer[Students];

  for (int i = 0; i < Students; i++)
  {
    int marks;
    cout << "Enter marks for Student " << i + 1 << ": ";
    cin >> marks;
    Marks[i].setValue(marks);
  }

  cout << "Recorded Marks:" << endl;
  for (int i = 0; i < Students; i++)
  {
    cout << "Student " << i + 1 << ": " << Marks[i].getValue() << endl;
  }

  for (int i = 0; i < Students; i++)
  {
    Marks[i].release();
  }

  delete[] Marks;
}
