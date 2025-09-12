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
	
	int x;
	cout << "Which element you want to find: ";
	cin >> x;
	
	int pos;
	for(int i = 0; i < n; i++){
		if(arr[i]==x){
			pos = i + 1;
			cout << "Element " <<x<<" found on position " << pos<<endl;
			return 0;
		}		
	}
	cout << "Element " <<x<<" not found!";
	return 0;
}
