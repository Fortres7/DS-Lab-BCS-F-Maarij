#include <iostream>
using namespace std;

void printNumbers(int n){
	if(n>0){
		cout << n << " ";
		printNumbers(n-1); 
	}
}

int main (){
	
	cout << "Enter Number: ";
	int n;
	cin >> n;
	if (n<=0){
		cout << "Invalid number";
	}	
	else {
	printNumbers(n);
	}
	return 0;
}
