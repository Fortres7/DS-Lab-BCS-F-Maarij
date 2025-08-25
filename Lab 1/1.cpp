#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount() {
        balance = 0.0;
    }

    BankAccount(double Balance) {
        balance = Balance;
    }

    BankAccount(const BankAccount& Temp) {
        balance = Temp.balance;
    }

    void withdraw(double amount) {
        if (amount <= balance)
            balance -= amount;
        else
            cout << "Cannot Withdraw" << endl;
    }
    void printBalance() {
        cout << "Balance: " << balance << endl;
    }
};

int main() {
  
    BankAccount account1;
    account1.printBalance();
    BankAccount account2(1000);
    account2.printBalance();
    BankAccount account3(account2);
    account3.printBalance();
    account3.withdraw(200);
    account3.printBalance();
    account2.printBalance();

    return 0;
}
