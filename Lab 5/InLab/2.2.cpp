#include <iostream>
using namespace std;
void functionB(int n);


void functionA(int n){
	if (n>=1){
		cout << n << " ";
		functionB(n-1);
	}
}

void functionB(int n){
	if (n>=1){
		cout << n << " ";
		functionA(n-1);
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
	functionA(n);
	}
	return 0;
}
