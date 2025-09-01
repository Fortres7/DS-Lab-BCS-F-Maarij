#include <iostream>
using namespace std;

int main() {
    int days;

    cout << "Enter number of days: ";
    cin >> days;

    double** temperatures = new double*[days];
    int* Readingperday = new int[days];

    for (int i = 0; i < days; i++) {
        cout << "\nEnter number of temperature readings for Day " << i + 1 << ": ";
        cin >> Readingperday[i];

        temperatures[i] = new double[Readingperday[i]];

        cout << "Enter " << Readingperday[i] << " temperature readings:\n";
        for (int j = 0; j < Readingperday[i]; j++) {
            cout << "Reading " << j + 1 << ": ";
            cin >> temperatures[i][j];
        }
    }

    double* Dailyavg = new double[days];
    int Hotday = 0, Coldday = 0;

    for (int i = 0; i < days; i++) {
        double sum = 0;
        for (int j = 0; j < Readingperday[i]; j++) {
            sum += temperatures[i][j];
        }
        Dailyavg[i] = sum / Readingperday[i];

        if (Dailyavg[i] > Dailyavg[Hotday]) {
            Hotday = i;
        }
        if (Dailyavg[i] < Dailyavg[Coldday]) {
            Coldday = i;
        }
    }

    cout << "Daily Average Temperatures:\n";
    for (int i = 0; i < days; i++) {
        cout << "Day " << i + 1 << ": " << Dailyavg[i] << "°C\n";
    }

    cout << "\nHottest Day: Day " << Hotday + 1 << Dailyavg[Hotday] << "C";
    cout << "\nColdest Day: Day " << Coldday + 1 << Dailyavg[Coldday] << "C\n";

    for (int i = 0; i < days; i++) {
        delete[] temperatures[i];
    }
    delete[] temperatures;
    delete[] Readingperday;
    delete[] Dailyavg;

    return 0;
}
