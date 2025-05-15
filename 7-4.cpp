#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

struct Student {
    char name[50];
    int marks;
    char grade;
};

// Custom manipulator for structured output formatting
ostream& format(ostream& os) {
    os << left << setw(20); // Aligns output neatly
    return os;
}

// Function to process file and display formatted student records
void generateReport(const char* filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    cout << "\n---------------- Student Performance Report ----------------\n";
    cout << format << "Name" << setw(10) << "Marks" << setw(8) << "Grade" << endl;
    cout << "------------------------------------------------------------\n";

    Student student;
    while (file.getline(student.name, 50, ',')) {
        // Expecting marks then grade on the same line after the comma
        file >> student.marks;
        file.ignore(1000, ' ');  // ignore the space after marks
        file >> student.grade;
        file.ignore(1000, '\n'); // move to the next line

        cerr << "[DEBUG] Read: " << student.name << ", " 
             << student.marks << ", "
             << student.grade << endl;
        cout << format << student.name << setw(10) << student.marks 
             << setw(8) << student.grade << endl;
    }

    file.close();
}

int main() {
    const char* filename = "students.txt";

    generateReport(filename);

    return 0;
}
