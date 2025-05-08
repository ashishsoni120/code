#include <iostream>
using namespace std;
int Bill = 0;
int QUANTITY = 2;
class Inventory
{
    string Name;
    int ID;
    int Quantity;
    int Price;
    double Total_Ammount = 0;

public:
    Inventory()
    {
        Name = "Default Name";
        ID = 0;
        Quantity = 0;
        Price = 0;
    }

    Inventory(int Id, string name, int quantity, int price)
    {
        Name = name;
        ID = Id;
        Quantity = quantity;
        Price = price;
        Total_Ammount += (Price * Quantity);
        cout<<"\n======== Item added successfully!! ========\n";
    }

    void UpdateQuantity(int x)
    {
        Quantity = x;
    }

    int GetId()
    {
        return ID;
    }

    void DetailOfProduct()
    {
        cout << "\n======== Detail of your order : ========\n";
        cout << "\tItem Name : " << Name << "\tProduct ID Number : " << ID << "\tProduct Price : " << Price << "\tQuantity Of Product : " << Quantity;
    }

    void BillOfProduct()
    {
        Bill = Bill + (Quantity * Price);
    }

    void Add_Stoke()
    {
        cout << "Enter name of the product : ";
        cin >> Name;

        cout << "Enter id of the product : ";
        cin >> ID;

        cout << "Enter price of the product : ";
        cin >> Price;

        cout << "Enter Quantity of the product : ";
        cin >> Quantity;
        Total_Ammount += (Price * Quantity);
        cout << "\n======== stoke Added Successfully!! ========\n";
    }

    void Remove_Stoke()
    {
        Total_Ammount -= (Price * Quantity);
        int Pid;
        cout << "Enter id of product you want to remove : ";
        cin >> Pid;
        if (ID == Pid)
        {
            Name = "Default Name";
            ID = 0;
            Quantity = 0;
            Price = 0;
            cout << "\n======== Stoke Removed successfully!! ========\n";
        }
        else
        {
            cout << "Invalid ID!!\n";
        }
    }
};
int main()
{
    int i, id, quantity, Item, ITEM, choice = 0;
    cout << "Enter No. of Item you want to Enter the Data : ";
    cin >> Item;

    Inventory Detail[QUANTITY];

    while (true)
    {

        cout << "\n\n";
        cout << " 1. For Enter The Data of product.\n";
        cout << " 2. change quantiy of product.\n";
        cout << " 3. for Display Bill & product information.\n";
        cout << " 4. Add stokes.\n";
        cout << " 5. Remove stokes.\n";

        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            for (i = 0; i < Item; i++)
            {
                int iD, qUANTITY, pRICE;
                string nAME;
                cout << "\nEnter Detail of " << i + 1 << " Item :\n";

                cout << "Enter Product ID: ";
                cin >> iD;
                cout << "Enter Product Name: ";
                cin >> nAME;
                cout << "Enter Quantity: ";
                cin >> qUANTITY;
                cout << "Enter Price: ";
                cin >> pRICE;

                Detail[i] = Inventory(iD, nAME, qUANTITY, pRICE);
            }
            break;
        case 2:

            for (int i = 0; i < Item; i++)
            {
                Detail[i].DetailOfProduct();
            }

            cout << "\nEnter ID of product to change quantity : ";
            cin >> id;

            for (int i = 0; i < Item; i++)
            {
                if (Detail[i].GetId() == id)
                {
                    cout << "Enter new quantity :";
                    cin >> quantity;

                    Detail[i].UpdateQuantity(quantity);

                    cout << "Quantity Updated!!";
                }
            }
            break;
        case 3:
            Bill = 0;
            for (int i = 0; i < Item; i++)
            {
                Detail[i].BillOfProduct();
            }

            for (int i = 0; i < Item; i++)
            {
                Detail[i].DetailOfProduct();
            }

            cout << "\nTotal Bill is : " << Bill << endl;

            break;
        case 4:

            cout << "Enter how many no. of item you want to add : ";
            cin >> ITEM;
            for (int i = 0; i < ITEM; i++)
            {
                if(i>ITEM)
                {
                    break;
                }
                else
                {
                int x = QUANTITY++;
                }
            }

            for (int i = QUANTITY; i < QUANTITY + ITEM; i++)
            {
                if(i>ITEM)
                {
                    break;
                }
                else
                {
                    Detail[i].Add_Stoke();
                }
                
            }

            for (int i = 0; i < QUANTITY; i++)
            {
                Detail[i].BillOfProduct();
            }

            for (int i = 0; i < QUANTITY; i++)
            {
                Detail[i].DetailOfProduct();
            }

            cout << "\nTotal Bill is : " << Bill << endl;

            break;

        case 5:

            for (int i = 0; i < Item; i++)
            {
                int y = QUANTITY--;
                Detail[i].Remove_Stoke();
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