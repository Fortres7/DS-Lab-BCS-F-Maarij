#include <iostream>
using namespace std;


int main(){
	
	int n;
	cout << "Enter number of elements you want to enter: ";
	cin >> n;
	
	int arr[n];
	
	for(int i = 0; i < n; i++){
		cout << "Enter Element# " << i+1 << ": ";
		cin >> arr[i]; 
	}	
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (arr[j] > arr[j + 1]) {
			int temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = temp;
			}
		}
	}	
	
	cout << "Sortred Array: " <<endl;
	cout << "[ ";	
		for(int i = 0; i < n; i++){
		cout << arr[i] << ", "; 
	}
	cout << "]";
	return 0;
}
