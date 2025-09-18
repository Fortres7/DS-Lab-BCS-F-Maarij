#include <iostream>
using namespace std;

int main() {
    int n, x;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) 
    cin >> arr[i];
    cout << "Enter element to search: ";
    cin >> x;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            cout << "Element found at index: " << i;
            return 0;
        }
    }
    cout << "Element not found!";
    return 0;
}
