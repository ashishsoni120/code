#include <iostream>
#include <limits> // For input validation
using namespace std;

// Function to safely read numerical input with validation
double getValidInput(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;

        // Check for valid numeric input
        if (cin.fail()) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input. Please enter a numeric value.\n";
        } else if (value < 0) {
            cout << "Value cannot be negative. Please enter a valid amount.\n";
        } else {
            return value;
        }
    }
}

int main() {
    cout << "Loan-to-Income Ratio Calculator\n";

    // Get loan amount
    double loanAmount = getValidInput("Enter total loan amount: ");

    // Get annual income (must be nonzero)
    double annualIncome;
    while (true) {
        annualIncome = getValidInput("Enter annual income: ");
        if (annualIncome == 0) {
            cout << "Annual income cannot be zero. Please enter a valid amount.\n";
        } else {
            break;
        }
    }

    // Calculate and display loan-to-income ratio
    double ratio = loanAmount / annualIncome;
    cout << "\nLoan-to-Income Ratio: " << ratio << endl;

    return 0;
}
