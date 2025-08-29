#include <iostream>
using namespace std;

int main(){
	
	int size;
	cout << "Enter size of array: ";
	cin >> size;
	
	int* arr = new int[size];
	
	cout << "Initializing array elemnts with 0\n";
	for(int i= 0; i<size; i++){
		arr[i] = 0;
	}
	
	cout<< "Enter elements\n";	
	for(int i= 0; i<size; i++){
		
		cout << "Enter elemnt #"<<i+1<<": ";
		cin >> arr[i];
	}
	char choice;
		
	do {
	    int pos, num;
	
	    
	    while (true) {
	        cout << "Enter position to update\n";
	        cin >> pos;
	        if (pos >= 0 && pos < size) {
	            break;  
	        }
	        cout << "Invalid position. Try again.\n";
	    }
	
	    cout << "Enter value: ";
	    cin >> num;
	
	    arr[pos] = num;
	
	    cout << "Still want to update? (y/n): ";
	    cin >> choice;
	} while (choice == 'y' || choice == 'Y');
	
	cout << "Updated array\n";
	cout << "Array: ";
	for(int i=0; i<size; i++){
		cout << arr[i];
	}	
	delete[] arr;		
	return 0;
}
