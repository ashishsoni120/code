#include <iostream>
#include <string.h>
using namespace std;
class BankAccount
{
    char Name[50];
    int AccountNumber;
    int AccountBalance;

public:
   
BankAccount()
{
    AccountBalance = 0;
    AccountNumber=0;
    strcpy(Name,"Default Name");
}
    BankAccount(int AccNumber, int AccBalanace, char name[])
    {
        AccountNumber = AccNumber;
        AccountBalance = AccBalanace;
        strcpy(Name, name);
    }

    void Find_Account()
    {
        int Acnum;
        cout << "Enter Your Account Number : ";
        cin >> Acnum;

        if (Acnum == AccountNumber)
        {
            cout << "\nAccount Holder Name : " << Name << "\nAccount Number : " << AccountNumber << "\nAccount Balance : " << AccountBalance;
        }
    }

    void DisplayData()
    {
        cout << "\nAccount Holder Name : " << Name << "\nAccount Number : " << AccountNumber << "\nAccount Balance : " << AccountBalance;
    }

    void DepositMoney()
    {
        int depositmoney;
        cout << "Enter Ammount you want to deposit : ";
        cin >> depositmoney;

        int acnum;
        cout << "Enter Your Account number : ";
        cin >> acnum;

        if (acnum == AccountNumber)
        {
            AccountBalance += depositmoney;
            cout << "New Balance is : " << AccountBalance << endl;
        }
    }

    void WithdrawMoney()
    {
        int withdrawmoney;
        cout << "Enter Ammount you want to withdraw : ";
        cin >> withdrawmoney;

        int acnum;
        cout << "Enter Your Account number : ";
        cin >> acnum;

        if (acnum == AccountNumber)
        {
            if (withdrawmoney < AccountBalance)
            {
                AccountBalance -= withdrawmoney;
                cout << "New Balance is : " << AccountBalance << endl;
            }
            else
            {
                cout << "Insufficient balance!";
            }
        }
    }
} Detail[5];
int main()
{
    int i, acnum, AcNum, Person, choice = 0;
    int Accountnumber, Accountbalance;
    char name[20];
    cout << "\nEnter No. of person : ";
    cin >> Person;

    while (choice != 6)
    {
        
        cout << "\nPress 1 : For Enter The Data of Account.\n";
        cout << "Press 2 : To check your account is in Bank or not.\n";
        cout << "Press 3 : For Display the data of accounts.\n";
        cout << "Press 4 : For deposit Money in you bank account.\n";
        cout << "Press 5 : For withdraw the money.\n";
        cout << "Press 6 : Exit.\n";

        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            for (i = 0; i < Person; i++)
            {
                cout << "\nEnter Detail of " << i + 1 << " Person : \n";

                cout << "Enter Name of Accountant : ";
                cin >> name;

                cout << "Enter Account Number : ";
                cin >> Accountnumber;

                cout << "Enter Bank Balance : ";
                cin >> Accountbalance;

               Detail[i] = BankAccount(Accountnumber, Accountbalance, name);
            }
            break;
        case 2:
            for (i = 0; i < Person; i++)
            {
                Detail[i].Find_Account();
            }
            break;
        case 3:
            for (i = 0; i < Person; i++)
            {
                Detail[i].DisplayData();
            }
            break;
        case 4:
            for (i = 0; i < Person; i++)
            {
                Detail[i].DepositMoney();
            }
            break;

        case 5:
            for (i = 0; i < Person; i++)
            {
                Detail[i].WithdrawMoney();
            }
            break;
        case 6:
            cout << "Existing!!";
            break;
        default:
            cout << "Invalid choice!";
            break;
        }
    }
}