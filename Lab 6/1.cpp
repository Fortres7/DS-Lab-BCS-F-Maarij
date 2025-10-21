#include <iostream>
using namespace std;


class Stack {

  int top;

  public:
  int size;
  int *arr;
  
  Stack(int size){
    top = -1;
    this->size = size;
    arr = new int[size];  
  }
  bool push(int x){
    if (top >= (size - 1))
    {
      cout << "Stack OverFlow" << endl;
      return false;
    }
    else
    {
      arr[++top] = x;
      cout << x << " Pushed into stack" << endl;
      return true;
    }    
  }
  int pop(){
    if (top < 0)
    {
      cout << "Stack is empty" << endl;
      return 0;
    }
    else 
    {
      int x = arr[top--];
      return x;
    }    
  }  
  int peek(){
    if (top < 0)
    {
      cout << "Stack is empty" << endl;
      return 0;
    }
    else 
    {
      int x = arr[top];
      return x;
    }    
  }  
  bool empty(){
    if (top < 0)
    {
      return true;
    }
    else{
      return false;
    }    
  }
  void printStack(){
    if (empty())
    {
      cout << "Stack is Empty" << endl;
      return;
    }
    else 
    {
      for (int i = 0; i < size; i++)
      {
        cout << pop() << endl;
      }   
      return;   
    }    
  }
};

int main(){
  cout << endl;

  int n;
  cout << "Enter Size of Stack: ";
  cin >> n;
  cout << endl;
  Stack s1(n); 

  for (int i = 0; i < n; i++)
  {
    cout << "Enter Element #" << i + 1 << ": ";
    int a;
    cin >> a;
    s1.push(a);
    cout << endl;
  }  
  cout << "Top Element: " << s1.peek();
  cout << endl;
  cout << "Stack: " << endl;
  s1.printStack();  
  

  return 0;
}
