#include <iostream>
using namespace std;

int combSort(int arr[], int n) {
    float shrink = 1.3;  
    int gap = n;        
    bool swapped = true;
    int swaps = 0;

    while (gap > 1 || swapped) {
        gap = (int)(gap / shrink);
        if (gap < 1) gap = 1;{
        swapped = false;}
      
        for (int i = 0; i + gap < n; ++i) {
            if (arr[i] > arr[i + gap]) {
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swapped = true;
                swaps++;
            }
        }
    }
    return swaps;
}

int bubbleSort(int arr[], int n) {
    int swaps = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }
        }
    }
    return swaps;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr1[n], arr2[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
        arr2[i] = arr1[i]
    }

    int combSwaps = combSort(arr1, n);
    int bubbleSwaps = bubbleSort(arr2, n);

    cout << "\nSorted array using Comb Sort: ";
    for (int i = 0; i < n; i++) {
    cout << arr1[i] << " "; }

    cout << "\nSorted array using Bubble Sort: ";
    for (int i = 0; i < n; i++) {
    cout << arr2[i] << " ";
    }

    cout << "\nTotal Swaps in Comb Sort: " << combSwaps;
    cout << "\nTotal Swaps in Bubble Sort: " << bubbleSwaps << endl;

    return 0;
}
