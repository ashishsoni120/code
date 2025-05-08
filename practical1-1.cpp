#include <iostream>
using namespace std;
struct BankAccount
{
    char Name[50];
    int AccountNumber;
    int AccountBalance;

    void GetData()
    {
        cout << "Enter Name of Accountant :";
        cin >> Name;

        cout << "Enter Account Number :";
        cin >> AccountNumber;

        cout << "Enter Bank Balance :";
        cin >> AccountBalance;
    }
    void DisplayData()
    {
        cout << "\nAccount Holder Name : " << Name << "\nAccount Number : " << AccountNumber << "\nAccount Balance : " << AccountBalance;
    }
    
    int DepositMoney()
    {
        int depositmoney;
        cout << "Enter Ammount you want to deposit : ";
        cin >> depositmoney;

        return depositmoney;
    }

    int WithdrawMoney()
    {
        int withdrawmoney;
        cout << "Enter Ammount you want to withdraw : ";
        cin >> withdrawmoney;
        return withdrawmoney;
    }

} Detail[20];
int main()
{
    int i, acnum, AcNum, Person, choice = 0;
    cout << "Enter No. of person : ";
    cin >> Person;

    while (choice != 6)
    {
        cout << "\nMenu\n";

        cout << "Press 1 : For Enter The Data of Account.\n";
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
                cout << "\nEnter Detail of " << i + 1 << " Person :\n";
                Detail[i].GetData();
            }
            break;
        case 2:
            cout << "Enter Your Account Number : ";
            cin >> AcNum;
            for (i = 0; i < Person; i++)
            {
                if (AcNum == Detail[i].AccountNumber)
                {
                    Detail[i].DisplayData();
                    break;
                }
                if (i == Person)
                {
                    cout << "There is not account of your.\n";
                }
            }
            break;
        case 3:
            for (i = 0; i < Person; i++)
            {
                Detail[i].DisplayData();
            }
            break;
        case 4:
            int x;
            cout << "Enter Your Account number : ";
            cin >> acnum;
            for (int i = 0; i < Person; i++)
            {
                if (acnum == Detail[i].AccountNumber)
                {
                    x = Detail[i].DepositMoney();
                    Detail[i].AccountBalance += x;
                    cout << "New Balance is : " << Detail[i].AccountBalance << endl;
                }
            }
            break;

        case 5:
            int y;
            cout << "Enter Your Account number : ";
            cin >> acnum;
            for (int i = 0; i < Person; i++)
            {
                if (acnum == Detail[i].AccountNumber)
                {
                    y = Detail[i].WithdrawMoney();
                    if (y < Detail[i].AccountBalance)
                    {
                        Detail[i].AccountBalance -= y;
                        cout << "New Balance is : " << Detail[i].AccountBalance << endl;
                    }
                    else
                    {
                        cout << "Insufficient balance!";
                    }
                }
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