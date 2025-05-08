#include <iostream>
#include <map>
using namespace std;

class BankAccount
{
    string Account_Holder_Name;
    int Account_Number;
    double Account_Balance;
    static int Total_Accounts;

public:
    BankAccount()
    {
        Account_Holder_Name = "";
        Account_Number = 0;
        Account_Balance = 0;
    }

    BankAccount(string name, int accnum, double accbal)
    {
        Account_Holder_Name = name;
        Account_Number = accnum;
        Account_Balance = accbal;
        Total_Accounts++;
    }

    void DisplayDetail()
    {
        cout << "\nAccount Holder Name: " << Account_Holder_Name
             << "\nAccount Number: " << Account_Number
             << "\nAccount Balance: " << Account_Balance << endl;
    }

    static int TotalAccount()
    {
        return Total_Accounts;
    }

    void TransferMoney(map<int, BankAccount> &Accounts, int receiverAccNum)
    {
        double Amount;
        cout << "\nEnter amount to transfer to " << receiverAccNum << ": ";
        cin >> Amount;

        if (Amount <= Account_Balance)
        {
                Account_Balance -= Amount;
                Accounts[receiverAccNum].Account_Balance += Amount;

                cout << "\nAmount of $" << Amount << " sent successfully!\n";
        }
        else
        {
            cout << "Insufficient balance!\n";
        }
    }
};

int BankAccount::Total_Accounts = 0;

int main()
{
    map<int, BankAccount> Accounts;

    int NumOfAccount, choice=0;
    cout << "Enter number of persons: ";
    cin >> NumOfAccount;

   
    while (choice!=5)
    {
        cout<<"\n Choices \n";
        cout << "\nPress 1 : For Enter The Data of Account.\n";
    
        cout << "Press 2 : For Display the data of accounts.\n";
        cout << "Press 3 : For sending the money.\n";
        cout << "Press 4 : For number of total accounts.\n";
        cout << "Press 5 : Exit.\n";

        cout<<"Enter choice : ";
        cin>>choice;

        switch (choice)
        {

        case 1:
            for (int i = 0; i < NumOfAccount; i++)
            {
                int AccNum;
                string Acc_Hol_Name;
                double AccBal;

                cout << "\nEnter details for person " << i + 1 << ":\n";

                cout << "\nEnter Name of Account Holder: ";
                cin >> Acc_Hol_Name;

                cout << "Enter Account Number: ";
                cin >> AccNum;

                cout << "Enter Bank Balance: ";
                cin >> AccBal;

                Accounts[AccNum] =  BankAccount(Acc_Hol_Name, AccNum, AccBal);
            }
            break;

        case 2:
            cout << "Detail Of the Bank is : \n";

            for (auto &i : Accounts)
            {
                i.second.DisplayDetail();
            }
            break;
        case 3:
            cout << endl;
            for (auto &i : Accounts)
            {
                i.second.DisplayDetail();
            }
            cout << endl;

            int SenderNum, ReceiverNum;
            cout << "Enter Account Number of Sender: ";
            cin >> SenderNum;

            cout << "Enter Account Number of Receiver: ";
            cin >> ReceiverNum;

            if (Accounts.find(SenderNum) != Accounts.end() && Accounts.find(ReceiverNum) != Accounts.end())
            {
                Accounts[SenderNum].TransferMoney(Accounts,ReceiverNum);
                cout<<"Thank You for come to our bank!!";
            }
            else
            {
                cout << "\nSender account not found!\n";
            }
            break;
            
        case 4:

            cout << "\nTotal Accounts: " << BankAccount::TotalAccount() << endl;
            break;

        case 5:

            cout<<"\n--------Existing---------";
        default:
            cout << "\nIn-efficient choice!!\n";
            break;
            return 0;
        }
    }
}