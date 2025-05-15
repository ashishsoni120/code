#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Generic_Bank_Account
{
protected:
    string Account_Type;
    int Account_number;
    int Account_Balance;

public:
    Generic_Bank_Account(string Account_type, int Account_Number, int Account_balance)
    {
        Account_Type = Account_type;
        Account_number = Account_Number;
        Account_Balance = Account_balance;
    }

    int getAccountNumber() const
    {
        return Account_number;
    }
    string getAccountType() const
    {
        return Account_Type;
    }

    void Display_Data() const
    {
        cout << "Account Number : "
             << Account_number << endl;

        cout << "Account Type : "
             << Account_Type << endl;

        cout << "Account Balance : "
             << Account_Balance << endl;
    }

    int Withdraw_Money(double Amt, int Acc_num)
    {
        if (Amt < 0) {
            cout << "Cannot withdraw negative amount." << endl;
            return 0;
        }

        if (Account_number == Acc_num)
        {
            Account_Balance -= Amt;
            cout << "Withdrawn Money is : " << Amt << endl;
            cout << "After Withdraw Account Balance : " << Account_Balance << endl;
            return 1;
        }
        else
        {
            cout << "Entered Account Number is incorrect." << endl;
            return 0;
        }
    }

    int Deposit_Money(double Amt, int Acc_num)
    {
        if (Amt < 0) {
            cout << "Cannot deposit negative amount." << endl;
            return 0;
        }

        if (Account_number == Acc_num)
        {
            Account_Balance += Amt;
            cout << "Deposit Money is : " << Amt << endl;
            cout << "After Deposit Account Balance : " << Account_Balance << endl;
            return 1;
        }
        else
        {
            cout << "Entered Account Number is incorrect." << endl;
            return 0;
        }
    }
};

class Saving : public Generic_Bank_Account
{
public:
    Saving(string Account_type, int Account_Number, int Account_balance)  : Generic_Bank_Account(Account_type, Account_Number, Account_balance) {}
};

class Current : public Generic_Bank_Account
{
    double Over_Draft_Limit;

public:
    Current(string Account_type, int Account_Number, int Account_balance, double Limit) : Generic_Bank_Account(Account_type, Account_Number, Account_balance)
    {
        Over_Draft_Limit = Limit;
    }

    int Withdraw_Money(double Amt, int Acc_num)
    {
        if (Account_number == Acc_num)
        {
            if (Over_Draft_Limit + Account_Balance < Amt)
            {
                cout << "You are exceeding the limit....." << endl;
                cout << "Enter valid Amount." << endl;
                return 0;
            }
            else
            {
                Account_Balance -= Amt;
                cout << "Withdrawn Money is : " << Amt << endl;
                cout << "After Withdraw Account Balance : " << Account_Balance << endl;
                return 1;
            }
        }
        else
        {
            cout << "Entered Account Number is incorrect.";
            return 0;
        }
    }
};

class Transaction
{
public:
    string type, operation;
    double amount;

    Transaction(string Operation, string t, double amt)
    {
        operation = Operation;
        type = t;
        amount = amt;
    }
};

int main()
{
    stack<Transaction> history;
    Generic_Bank_Account* accounts[5];
    int Person;
    int Acc_num, Acc_Bal;
    string Acc_type;

    cout << "Enter how many account data you want to enter : ";
    cin >> Person;


    for (int i = 0; i < Person; i++)
    {
        cout << "Enter Account Number: ";
        cin >> Acc_num;
        if (Acc_num < 0) {
            cout << "Account number cannot be negative. Please try again." << endl;
            i--;

        }

        cout << "Enter Account Balance: ";
        cin >> Acc_Bal;
        if (Acc_Bal < 0) {
            cout << "Account balance cannot be negative. Please try again." << endl;
            i--;

        }

        cout << "Enter Account Type (Saving/Current): ";
        cin >> Acc_type;

        // Convert to lowercase

        for(int i=0; Acc_type[i] != '\0';i++)
        {
            if(Acc_type[i] >= 'A' && Acc_type[i]<='Z')
            {
                Acc_type[i]+=32;
            }
        }
        string lower_acc_type = Acc_type;

        if (lower_acc_type == "current")
        {
            double over_d_limit;
            cout << "Enter over draft limit: ";
            cin >> over_d_limit;
            if (over_d_limit < 0) {
                cout << "Over draft limit cannot be negative. Please try again." << endl;
                i--;
            }
            accounts[i] = new Current(Acc_type, Acc_num, Acc_Bal, over_d_limit);
        }
        else if (lower_acc_type == "saving")
        {
            accounts[i] = new Saving(Acc_type, Acc_num, Acc_Bal);
        }
        else
        {
            cout << "Enter valid account type..." << endl;
            i--;
        }
    }

    int choice = 0;
    while (choice != 5)  // Changed from 6 to 5 to match the menu
    {
        cout << "\n1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Undo" << endl;
        cout << "4. Show Details" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: // Deposit
        {
            cout << "Enter account number: ";
            cin >> Acc_num;
            double dep_amt;
            cout << "Enter amount to deposit: ";
            cin >> dep_amt;

            bool found = false;
            for (int i = 0; i < Person; i++)
            {
                if (accounts[i]->Deposit_Money(dep_amt, Acc_num))
                {
                    history.push(Transaction("Deposit", accounts[i]->getAccountType(), dep_amt));
                    found = true;
                    break;
                }
            }
            break;
        }

        case 2: // Withdraw
        {
            cout << "Enter account number: ";
            cin >> Acc_num;
            double with_amt;
            cout << "Enter amount to withdraw: ";
            cin >> with_amt;

            bool found = false;
            for (int i = 0; i < Person; i++)
            {
                if (accounts[i]->Withdraw_Money(with_amt, Acc_num))
                {
                    history.push(Transaction("Withdraw", accounts[i]->getAccountType(), with_amt));
                    found = true;
                    break;
                }
            }
            break;
        }

        case 3: // Undo
            if (!history.empty())
            {
                Transaction last = history.top();
                history.pop();

                // Find the account and reverse the transaction
                for (int i = 0; i < Person; i++)
                {
                    if (accounts[i]->getAccountType() == last.type)
                    {
                        if (last.operation == "Deposit")
                        {
                            accounts[i]->Withdraw_Money(last.amount, accounts[i]->getAccountNumber());
                            cout << "Undid deposit of " << last.amount << endl;
                        }
                        else if (last.operation == "Withdraw")
                        {
                            accounts[i]->Deposit_Money(last.amount, accounts[i]->getAccountNumber());
                            cout << "Undid withdrawal of " << last.amount << endl;
                        }
                        break;
                    }
                }
            }
            else
            {
                cout << "Nothing to undo!" << endl;
            }
            break;

        case 4: // Show Details
            cout << "\nDetails of all Accounts:" << endl;
            for (int i = 0; i < Person; i++)
            {
                accounts[i]->Display_Data();
                cout << "---------------------" << endl;
            }
            break;

        case 5: // Exit
            cout << "Exiting...";
          break;
        default:
            cout << "Enter valid choice" << endl;
            break;
        }
    }
    return 0;
}
