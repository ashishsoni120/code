#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Item {
    char name[50];
    int quantity;
    double price;
};

// Function to add a new item to inventory
void addItem(const char* filename) {
    ofstream file(filename, ios::app); // Append mode to retain existing data
    if (!file) {
        cerr << "Error: Unable to open file for writing.\n";
        return;
    }

    Item item;
    cout << "Enter item name: ";
    cin.ignore();
    cin.getline(item.name, 50);
    cout << "Enter quantity: ";
    cin >> item.quantity;
    cout << "Enter price: ";
    cin >> item.price;

    file << item.name << "," << item.quantity << "," << item.price << endl;
    file.close();

    cout << "Item added successfully!\n";
}

// Function to display all inventory items
void viewInventory(const char* filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Unable to open file for reading.\n";
        return;
    }

    Item item;
    cout << "Inventory List:\n";
    while (file.getline(item.name, 50, ',') &&
           file >> item.quantity &&
           file.ignore() &&
           file >> item.price) {
        file.ignore();
        cout << "Name: " << item.name << ", Quantity: " << item.quantity << ", Price: $" << item.price << endl;
    }

    file.close();
}

// Function to search for an item by name efficiently
void searchItem(const char* filename, const char* searchName) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Unable to open file for reading.\n";
        return;
    }

    Item item;
    bool found = false;
    while (file.getline(item.name, 50, ',') &&
           file >> item.quantity &&
           file.ignore() &&
           file >> item.price) {
        file.ignore();
        if (strcmp(item.name, searchName) == 0) {
            found = true;
            cout << "Item found!\nName: " << item.name << ", Quantity: " << item.quantity << ", Price: $" << item.price << endl;
            break; // Efficient retrieval
        }
    }

    if (!found) {
        cout << "Item not found.\n";
    }

    file.close();
}

int main() {
    const char* filename = "inventory.txt";
    int choice;

    do {
        cout << "\nInventory Management:\n1. Add Item\n2. View Inventory\n3. Search Item\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addItem(filename);
                break;
            case 2:
                viewInventory(filename);
                break;
            case 3: {
                char searchName[50];
                cout << "Enter item name to search: ";
                cin.ignore();
                cin.getline(searchName, 50);
                searchItem(filename, searchName);
                break;
            }
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
