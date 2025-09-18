#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int a[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++){
    cout << "Enter Element " << i+1 << ": "; 
    cin >> a[i];
    }

    cout << "Unsorted array: ";
    for (int i = 0; i < n; i++){
    cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
    }
    return 0;
}
