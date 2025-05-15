#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Custom comparator to sort students by scores in descending order
bool compareStudents(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second; // Sorts based on scores (descending order)
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<pair<string, int>> students; // Dynamic storage for name-score pairs

    cout << "Enter student names and scores:\n";
    for (int i = 0; i < n; i++) {
        string name;
        int score;
        cin.ignore();
        cout << "Name: ";
        getline(cin, name);
        cout << "Score: ";
        cin >> score;
        students.emplace_back(name, score); // Insert name-score pairs dynamically
    }

    // Sorting students based on scores using custom comparator
    sort(students.begin(), students.end(), compareStudents);

    // Display ranked list
    cout << "\nRanked Student List:\n";
    for (size_t i = 0; i < students.size(); i++) {
        cout << "Rank " << i + 1 << ": " << students[i].first << " - Score: " << students[i].second << endl;
    }

    return 0;
}
