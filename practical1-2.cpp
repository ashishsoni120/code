#include <iostream>
using namespace std;
int Bill = 0;
class DataAccount
{
    string Name;
    int ID;
    int Quantity;
    int price;
    

public:
    void AddProduct()
    {
        cout << "Enter Name of Product :";
        cin >> Name;

        cout << "Enter ID :";
        cin >> ID;

        cout << "Enter price : ";
        cin >> price;

        cout << "Enter Quantity : ";
        cin >> Quantity;
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
        cout << "\nDetail of your order : \n";
        cout << "\nItem Name : " << Name << "\nProduct ID Number : " << ID << "\nProduct Price : " << price << "\nQuantity Of Product : " << Quantity;
    }

    void BillOfProduct()
    {
        Bill = Bill + (Quantity * price);
    }

} Detail[20];
int main()
{
    int i, x, z, id, quantity, NewQuantity, Item, choice = 0;
    cout << "Enter No. of Item you want : ";
    cin >> Item;

    while (choice != 3)
    {
        cout << "\nMenu\n";

        cout << "Press 1 : For Enter The Data of product.\n";
        cout << "Press 2 : change quantiy pf product.\n";
        cout << "Press 3 : for Bill.\n";

        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            for (i = 0; i < Item; i++)
            {
                cout << "\nEnter Detail of " << i + 1 << " Item :\n";
                Detail[i].AddProduct();
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
        default:
            cout << "Invalid choice!";
            break;
        }
    }
}