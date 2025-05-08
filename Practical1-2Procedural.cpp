#include <iostream>
using namespace std;
int temp = 0, Bill = 0;
struct Inventory
{
    char Name[50];
    int ID;
    int Quantity;
    int price;
} Detail[20];

void AddProduct(struct Inventory Detail[], int x)
{
    for (int i = 0; i < x; i++)
    {
        cout << "\nEnter Detail of " << i + 1 << " Item :\n";

        cout << "Enter Name of Product :";
        cin >> Detail[i].Name;

        cout << "Enter ID :";
        cin >> Detail[i].ID;

        cout << "Enter price : ";
        cin >> Detail[i].price;

        cout << "Enter Quantity : ";
        cin >> Detail[i].Quantity;
    }
}

void DetailOfProduct(struct Inventory Detail[], int b)
{
    cout << "\nDetail of your order : \n";
    for (int i = 0; i < b; i++)
    {
        cout << "\n\tItem Name : " << Detail[i].Name << "\tProduct ID Number : " << Detail[i].ID << "\tProduct Price : " << Detail[i].price << "\tQuantity Of Product : " << Detail[i].Quantity;
    }
}

void BillOfProduct(struct Inventory Detail[], int a)
{
    for (int i = 0; i < a; i++)
    {
        Bill = Bill + (Detail[i].Quantity * Detail[i].price);
    }
}
int main()
{
    int i, x, z, id, quantity, NewQuantity, choice = 0;
    int Item;
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
            AddProduct(Detail,Item);
            break;
        case 2:
            DetailOfProduct(Detail,Item);
            
            cout << "\nEnter how many product quantity you want to change :";
            cin >> NewQuantity;

            cout << "\nEnter ID of product to change quantity : ";
            cin >> id;

            for (int i = 0; i < NewQuantity; i++)
            {
                if (id == Detail[i].ID)
                {
                    cout << "\nEnter new quantity :";
                    cin >> quantity;
                    Detail[i].Quantity = quantity;
                    cout << "Quantity Updated Successfully!\n";
                    break;
                }
            }
            break;
        case 3:
                BillOfProduct(Detail, Item);
            
                DetailOfProduct(Detail, Item);
        
            if (choice = 3)
            {
                cout << "\nTotal Bill is : " << Bill << endl;
                exit(0);
            }
            break;
        default:
            cout << "Invalid choice!";
            break;
        }
    }
}