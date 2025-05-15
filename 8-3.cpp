#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cout << "Enter number of transaction IDs: ";
    cin >> n;

    set<int> uniqueTransactions; // Associative container for uniqueness & sorting

    cout << "Enter transaction IDs:\n";
    for (int i = 0; i < n; i++) {
        int id;
        cin >> id;
        uniqueTransactions.insert(id); // Automatically removes duplicates
    }

    cout << "\nFiltered Unique Transaction IDs (Sorted Order):\n";
    for (int transaction : uniqueTransactions) {
        cout << transaction << " ";
    }
    cout << endl;

    return 0;
}
