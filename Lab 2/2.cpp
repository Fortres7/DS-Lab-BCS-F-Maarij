#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    cout << "Enter rows: ";
    cin >> rows;
    cout << "Enter columns: ";
    cin >> cols;

    int** arr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

    cout << "Initializing array with 0"<<endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) { 
            arr[i][j] = 0;
        }
    }

    cout << "Class seating arrangement:"<<endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) { 
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int total = rows * cols; 
    int seats;
    cout << "How many seats do you want to occupy?: ";
    cin >> seats;

    if (seats > total) {
        cout << "No seat availability"<<endl;
    } else {
        cout << "Enter seat positions to occupy (row and column indices starting from 0):"<<endl;
        for (int k = 0; k < seats; k++) {
            int r, c;
            while (true) {
                cout << "Seat #" << k + 1 << " - Enter row (0 to " << rows - 1 << "): ";
                cin >> r;
                cout << "Seat #" << k + 1 << " - Enter column (0 to " << cols - 1 << "): ";
                cin >> c;

                if (r >= 0 && r < rows && c >= 0 && c < cols) {
                    if (arr[r][c] == 0) {
                        arr[r][c] = 1;  
                        break;
                    } else {
                        cout << "Seat already occupied. Choose a different seat."<<endl;
                    }
                } else {
                    cout << "Try again."<<endl;
                }
            }
        }

        cout << "Updated seating arrangement:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
