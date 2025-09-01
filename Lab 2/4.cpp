#include <iostream>
using namespace std;

double* resizeArray(double* oldArr, int oldSize, int newSize) {
    if (newSize == oldSize) return oldArr;

    double* newArr = new double[newSize];
    int limit = (oldSize < newSize) ? oldSize : newSize;

    for (int i = 0; i < limit; i++) {
        newArr[i] = oldArr[i];
    }

    delete[] oldArr;
    return newArr;
}

int main() {
    int size;
    cout << "Enter number of months: ";
    cin >> size;

    double* expenses = new double[size];

    for (int i = 0; i < size; i++) {
        cout << "Enter expense for month " << i + 1 << ": RS.";
        cin >> expenses[i];
    }

    char choice;
    cout << "\nDo you want to resize the months? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        int newSize;
        cout << "Enter new number of months: ";
        cin >> newSize;

        expenses = resizeArray(expenses, size, newSize);

        if (newSize > size) {
            for (int i = size; i < newSize; i++) {
                cout << "Enter expense for month " << i + 1 << ": RS.";
                cin >> expenses[i];
            }
        }

        size = newSize; 
    }

    cout << "\nFinal Monthly Expenses:\n";
    double total = 0;
    for (int i = 0; i < size; i++) {
        cout << "Month " << i + 1 << ": RS." << expenses[i] << endl;
        total += expenses[i];
    }

    cout << "\nTotal Expenses: RS." << total;
    cout << "\nAverage Monthly Expense: RS." << (size > 0 ? total / size : 0) << endl;

    delete[] expenses;

    return 0;
}
