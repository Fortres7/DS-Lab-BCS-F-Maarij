#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    while (low <= high && x >= arr[low] && x <= arr[high]) {
        int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]);
        if (arr[pos] == x) return pos;
        if (arr[pos] < x) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
}

int main() {
    int n, x;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++){
    cout << "Enter Element " << i+1 << ": ";  
    cin >> arr[i];
    }
    cout << "Enter element to search: ";
    cin >> x;
    int result = interpolationSearch(arr, n, x);
    if (result != -1) {
    cout << "Element found at index: " << result;
    }
    else cout << "Element not found!";
    return 0;
}
