#include <iostream>
#include <vector>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    double balance;
    vector<string> transactionLog; // Stores transaction history

public:
    // Constructor
    BankAccount(string name, double initialBalance) : accountHolder(name), balance(initialBalance) {}

    // Deposit funds securely
    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Error: Deposit amount must be positive.\n";
            return;
        }
        balance += amount;
        transactionLog.push_back("Deposited: $" + to_string(amount));
        cout << "Deposit successful! New balance: $" << balance << endl;
    }

    // Withdraw funds securely with error handling
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Error: Withdrawal amount must be positive.\n";
            return;
        }
        if (amount > balance) {
            cout << "Error: Insufficient funds. Available balance: $" << balance << endl;
            return;
        }
        balance -= amount;
        transactionLog.push_back("Withdrew: $" + to_string(amount));
        cout << "Withdrawal successful! New balance: $" << balance << endl;
    }

    // Display transaction history
    void showTransactionLog() {
        cout << "\nTransaction History for " << accountHolder << ":\n";
        for (const string& entry : transactionLog) {
            cout << entry << endl;
        }
    }

    // Display account details
    void showAccountDetails() {
        cout << "\nAccount Holder: " << accountHolder << "\nCurrent Balance: $" << balance << endl;
    }
};

int main() {
    string name;
    double initialBalance;

    cout << "Enter account holder name: ";
    getline(cin, name);

    cout << "Enter initial balance: ";
    cin >> initialBalance;

    BankAccount account(name, initialBalance);

    int choice;
    double amount;

    do {
        cout << "\nBanking System Menu:\n1. Deposit\n2. Withdraw\n3. View Transactions\n4. View Account Details\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter deposit amount: ";
                cin >> amount;
                account.deposit(amount);
                break;
            case 2:
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                account.withdraw(amount);
                break;
            case 3:
                account.showTransactionLog();
                break;
            case 4:
                account.showAccountDetails();
                break;
            case 5:
                cout << "Exiting banking system...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
