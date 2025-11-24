#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    float balance;
    string ownerName;

public:
    BankAccount(int acc, float bal, string owner) {
        accountNumber = acc;
        balance = bal;
        ownerName = owner;
    }
    void credit(float amount) {
        balance += amount;
    }
    void debit(float amount) {
        if (amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient balance!" << endl;
    }
    void display() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Owner: " << ownerName << endl;
        cout << "Balance: " << balance << endl;
    }
};
int main() {
    BankAccount acc1(12345, 5000, "raj");

    acc1.credit(2000);
    acc1.debit(1000);
    acc1.display();

    return 0;
}
