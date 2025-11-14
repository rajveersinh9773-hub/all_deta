#include <iostream>
using namespace std;

const int MAX_NAME_LENGTH = 100;

void copyString(char* dest, const char* src) 
{
    int i = 0;
    while (src[i] != '\0' && i < MAX_NAME_LENGTH - 1) 
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

class BankAccount {
protected:
    int accountNumber;
    char accountHolderName[MAX_NAME_LENGTH];
    double balance;

public:
    BankAccount(int accNum, const char* accHolder, double bal) 
    {
        accountNumber = accNum;
        balance = bal;
        copyString(accountHolderName, accHolder);
    }

    virtual void deposit(double amount) 
    {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    virtual void withdraw(double amount) 
    {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    double getBalance() const 
    {
        return balance;
    }

    virtual void displayAccountInfo() const 
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }

    virtual void calculateInterest() 
    {
        cout << "No interest calculation for base account." << endl;
    }

    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount 
{
private:
    double interestRate;

public:
    SavingsAccount(int accNum, const char* accHolder, double bal, double rate)
        : BankAccount(accNum, accHolder, bal), interestRate(rate) {}

    void calculateInterest() override 
    {
        double interest = balance * interestRate / 100;
        cout << "Savings Account Interest: " << interest << endl;
    }

    void displayAccountInfo() const override 
    {
        BankAccount::displayAccountInfo();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CheckingAccount(int accNum, const char* accHolder, double bal, double limit)
        : BankAccount(accNum, accHolder, bal), overdraftLimit(limit) {}

    void withdraw(double amount) override 
    {
        if (amount <= balance + overdraftLimit) 
        {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } 
        else 
        {
            cout << "Withdrawal exceeds overdraft limit!" << endl;
        }
    }

    void displayAccountInfo() const override 
    {
        BankAccount::displayAccountInfo();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }

    void calculateInterest() override {
        cout << "No interest for Checking Account." << endl;
    }
};

class FixedDepositAccount : public BankAccount 
{
private:
    int term; 

public:
    FixedDepositAccount(int accNum, const char* accHolder, double bal, int t)
        : BankAccount(accNum, accHolder, bal), term(t) {}

    void calculateInterest() override 
    {
        double rate = 7.5; // fixed interest rate
        double interest = (balance * rate * term) / (12 * 100);
        cout << "Fixed Deposit Interest for " << term << " months: " << interest << endl;
    }

    void displayAccountInfo() const override 
    {
        BankAccount::displayAccountInfo();
        cout << "Term: " << term << " months" << endl;
    }
};

void showMenu() {
    cout << "\n--- Bank Menu ---\n";
    cout << "1. Create Savings Account\n";
    cout << "2. Create Checking Account\n";
    cout << "3. Create Fixed Deposit Account\n";
    cout << "4. Deposit Amount\n";
    cout << "5. Withdraw Amount\n";
    cout << "6. Display Account Info\n";
    cout << "7. Calculate Interest\n";
    cout << "8. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    const int MAX_ACCOUNTS = 100;
    BankAccount* accounts[MAX_ACCOUNTS];
    int accountCount = 0;

    int choice;
    do {
        showMenu();
        cin >> choice;

        if (choice >= 1 && choice <= 3 && accountCount >= MAX_ACCOUNTS) 
        {
            cout << "Cannot create more accounts.\n";
            continue;
        }

        if (choice == 1) {
            int accNum;
            char name[MAX_NAME_LENGTH];
            double bal, rate;
            cout << "Enter Account Number: ";
            cin >> accNum;
            cout << "Enter Account Holder Name: ";
            cin.ignore(); 
            cin.getline(name, MAX_NAME_LENGTH);
            cout << "Enter Initial Balance: ";
            cin >> bal;
            cout << "Enter Interest Rate (%): ";
            cin >> rate;
            accounts[accountCount++] = new SavingsAccount(accNum, name, bal, rate);
            cout << "Savings Account Created.\n";
        }
        else if (choice == 2) {
            int accNum;
            char name[MAX_NAME_LENGTH];
            double bal, limit;
            cout << "Enter Account Number: ";
            cin >> accNum;
            cout << "Enter Account Holder Name: ";
            cin.ignore();
            cin.getline(name, MAX_NAME_LENGTH);
            cout << "Enter Initial Balance: ";
            cin >> bal;
            cout << "Enter Overdraft Limit: ";
            cin >> limit;
            accounts[accountCount++] = new CheckingAccount(accNum, name, bal, limit);
            cout << "Checking Account Created.\n";
        }
        else if (choice == 3) {
            int accNum, term;
            char name[MAX_NAME_LENGTH];
            double bal;
            cout << "Enter Account Number: ";
            cin >> accNum;
            cout << "Enter Account Holder Name: ";
            cin.ignore();
            cin.getline(name, MAX_NAME_LENGTH);
            cout << "Enter Initial Balance: ";
            cin >> bal;
            cout << "Enter Term (in months): ";
            cin >> term;
            accounts[accountCount++] = new FixedDepositAccount(accNum, name, bal, term);
            cout << "Fixed Deposit Account Created.\n";
        }
        else if (choice == 4 || choice == 5 || choice == 6 || choice == 7) {
            int index;
            cout << "Enter Account Index (0 to " << accountCount - 1 << "): ";
            cin >> index;

            if (index < 0 || index >= accountCount) 
            {
                cout << "Invalid account index.\n";
                continue;
            }

            if (choice == 4) {
                double amt;
                cout << "Enter Amount to Deposit: ";
                cin >> amt;
                accounts[index]->deposit(amt);
            }
            else if (choice == 5) {
                double amt;
                cout << "Enter Amount to Withdraw: ";
                cin >> amt;
                accounts[index]->withdraw(amt);
            }
            else if (choice == 6) {
                accounts[index]->displayAccountInfo();
            }
            else if (choice == 7) {
                accounts[index]->calculateInterest(); 
            }
        }
        else if (choice == 8) {
            cout << "Thank you for using the Banking System.\n";
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 8);

    // Clean up
    for (int i = 0; i < accountCount; ++i) 
    {
        delete accounts[i];
    }

    return 0;
}