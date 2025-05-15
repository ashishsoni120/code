#include <iostream>
#include <iomanip>
using namespace std;

// Custom manipulator for currency formatting
ostream& currency(ostream& os) {
    return os << "₹ "; // Change to "$" for USD, etc.
}

int main() {
    // Sample student data
    struct Student {
        string name;
        int marks;
        double tuitionFee;
    };

    Student students[] = {
        {"Alice Johnson", 85, 150000.75},
        {"Bob Williams", 78, 145500.50},
        {"Charlie Smith", 92, 160000.00},
        {"Diana Brown", 88, 152750.25}
    };

    int totalStudents = sizeof(students) / sizeof(students[0]);

    // Header
    cout << left << setw(20) << "Name" << setw(10) << "Marks" << setw(15) << "Tuition Fee" << endl;
    cout << setfill('-') << setw(45) << "" << setfill(' ') << endl;

    // Display student data with proper alignment and formatting
    for (int i = 0; i < totalStudents; i++) {
        cout << left << setw(20) << students[i].name
             << setw(10) << students[i].marks
             << currency << fixed << setprecision(2) << setw(12) << students[i].tuitionFee
             << endl;
    }

    return 0;
}
