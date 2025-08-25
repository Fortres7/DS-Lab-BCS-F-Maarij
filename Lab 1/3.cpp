#include <iostream>
using namespace std;

class Box {
    int* integers;
    int size;

public:
    Box(int size) {
        this->size = size;
        integers = new int[size];
        for (int i = 0; i < size; i++) {
            cout << "Enter number: ";
            cin >> integers[i];
        }
    }

    Box(const Box& obj) {
        size = obj.size;
        integers = new int[size];
        for (int i = 0; i < size; i++) {
            integers[i] = obj.integers[i];
        }
        cout << "Copy constructor called\n";
        cout << "Object created\n";
    }

    Box& operator=(const Box& obj) {
        size = obj.size;
        integers = new int[size];
        for (int i = 0; i < size; i++) {
            integers[i] = obj.integers[i];
        }
        cout << "Copy assignment operator called\n";
        cout << "Object created\n";
        return *this;
    }

    ~Box() {
        delete[] integers;
        cout << "Destructor is called\n";
    }

    void displaydetails() {
        cout << "Details: ";
        for (int i = 0; i < size; i++) {
            cout << integers[i] << " ";
        }
        cout << endl;
    }

    void set(int index, int value) {
        if (index >= 0 && index < size) {
            integers[index] = value;
        }
    }
};

int main() {
    Box B1(10);
    B1.displaydetails();
    Box B2 = B1; 
    B2.set(3, 100); 
    B2.displaydetails();
    B1.displaydetails();
    cout << "No Change occurs to box 1(B1)\n" ;
    Box B3(7); 
    B3 = B1;
    B3.set(4, 150); 
    B3.displaydetails();
    B1.displaydetails();

}

//In this program we use dynamic memory to store an integer in the Box class. 
//We create a copy constructor and an assignment operator to make a deep copy. 
//When we copy one object to another a new memory space is created and the data is copied over. 
//If we change one object it doesnt affect the other this means it is Deep copy.
//Shallow copy just copies the memory address and both objects point to the same memory. 
//This can lead to problems like one object changing the others data.
