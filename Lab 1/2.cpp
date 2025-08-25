#include <iostream>
#include <cstring>
using namespace std;

class Exam {
private:
    char* nameptr;
    char* dateptr;
    double* scoreptr;

public:
    Exam(const char* name, const char* date, double score) {
        nameptr = new char[strlen(name) + 1];
        strcpy(nameptr, name);

        dateptr = new char[strlen(date) + 1];
        strcpy(dateptr, date);

        scoreptr = new double;
        *scoreptr = score;
    }

    Exam(const Exam& obj) {
        nameptr = obj.nameptr;     
        dateptr = obj.dateptr;     
        scoreptr = obj.scoreptr;   
    }


    void setName(const char* name) {
        strcpy(nameptr, name); 
    }

    void setDate(const char* date) {
        strcpy(dateptr, date);
    }

    void setScore(double score) {
        *scoreptr = score;
    }

    void printDetails() {
        cout << "Name: " << nameptr << endl;
        cout << "Date: " << dateptr << endl;
        cout << "Score: " << *scoreptr << endl;
    }
    ~Exam() {
        delete[] nameptr;
        delete[] dateptr;
        delete scoreptr;
    }
};

int main() {
    Exam exam1("Maarij", "2025-08-25", 100);
    cout << "Original exam:\n";
    exam1.printDetails();

    Exam exam2 = exam1;
    cout << "\nCopied exam:\n";
    exam2.printDetails();

    exam2.setScore(80);
    exam2.setName("Ahmed");
    exam2.setDate("2025-09-01");

    cout << "\nAfter modifying:\n";
    cout << "Original exam:\n";
    exam1.printDetails();
    cout << "\nCopied exam:\n";
    exam2.printDetails();

    return 0;
}
