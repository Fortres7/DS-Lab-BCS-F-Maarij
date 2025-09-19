#include <iostream>
using namespace std;

int sumTail(int n, int total = 0) {
    if (n == 0) 
        return total;  
    return sumTail(n - 1, total + n); 
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;    
    cout << "Sum: " << sumTail(n) << endl;
    return 0;
}
