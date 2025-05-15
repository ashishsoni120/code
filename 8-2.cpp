#include <iostream>
#include <map>
#include <sstream>
using namespace std;

void analyzeWordFrequency(const string& text) {
    map<string, int> wordFrequency; // Associative container to store word counts
    stringstream ss(text);
    string word;

    // Extract words and update frequency
    while (ss >> word) {
        wordFrequency[word]++;
    }

    // Display word frequencies in an organized manner
    cout << "\nWord Frequency Distribution:\n";
    for (const auto& entry : wordFrequency) {
        cout << entry.first << ": " << entry.second << endl;
    }
}

int main() {
    string text;
    cout << "Enter a sentence or paragraph:\n";
    getline(cin, text);

    analyzeWordFrequency(text);

    return 0;
}
