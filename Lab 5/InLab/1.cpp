#include <iostream>
using namespace std;

int calculateFactorial(int n){
	if (n<=1){
		return 1;
	}
	else{
		return n*calculateFactorial(n-1);
	}
}

int main (){
	
	cout << "Enter Number: ";
	int n;
	cin >> n;
	cout << "Factorial of " << n << " is: " << calculateFactorial(n);
	
	return 0;
}
