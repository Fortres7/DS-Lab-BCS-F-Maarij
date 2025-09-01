#include <iostream>
using namespace std;

int main() {
    int departments;
    cout << "Enter number of departments: ";
    cin >> departments;

    int** salary = new int*[departments];
    int* EmpNum = new int[departments];

    for (int i = 0; i < departments; i++) {
        cout << "Enter number of employees in Department " << i + 1 << ": ";
        cin >> EmpNum[i];

        salary[i] = new int[EmpNum[i]];

        cout << "Enter salaries for Department " << i + 1 << ":\n";
        for (int j = 0; j < EmpNum[i]; j++) {
            cout << "Employee " << j + 1 << ": Rs.";
            cin >> salary[i][j];
        }
    }

    cout << "Highest salary in each department:\n";
    for (int i = 0; i < departments; i++) {
        int maxSalary = salary[i][0];
        for (int j = 1; j < EmpNum[i]; j++) {
            if (salary[i][j] > maxSalary) {
                maxSalary = salary[i][j];
            }
        }
        cout << "Department " << i + 1 << ": Rs." << maxSalary << endl;
    }

    int Maxavgdep = 0;
    double Maxavg = 0;

    cout << "\nAverage salary of each department:\n";
    for (int i = 0; i < departments; i++) {
        int sum = 0;
        for (int j = 0; j < EmpNum[i]; j++) {
            sum += salary[i][j];
        }
        double avg = sum / EmpNum[i];
        cout << "Department " << i + 1 << ": Rs." << avg << endl;

        if (avg > Maxavg) {
            Maxavg = avg;
            Maxavgdep = i;
        }
    }

    cout << "\nDepartment with highest average salary: Department " << Maxavgdep + 1;
    cout << " (Rs." << Maxavg << ")\n";

    for (int i = 0; i < departments; i++) {
        delete[] salary[i];
    }
    delete[] salary;
    delete[] EmpNum;

    return 0;
}

