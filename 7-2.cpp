#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class TextProcessor {
private:
    char** lines; // Manually managed dynamic array
    int lineCount;
    int wordCount;
    int charCount;

public:
    TextProcessor() : lines(nullptr), lineCount(0), wordCount(0), charCount(0) {}

    bool loadFile(const char* filename) {
        ifstream file(filename);
        if (!file) {
            cerr << "Error: Could not open file " << filename << endl;
            return false;
        }

        const int MAX_LINES = 1000; // Dynamic allocation limit
        lines = new char*[MAX_LINES];

        char buffer[1024]; // Temporary buffer for reading lines
        while (file.getline(buffer, sizeof(buffer))) {
            lines[lineCount] = new char[strlen(buffer) + 1]; // Allocate memory for line
            strcpy(lines[lineCount], buffer); // Copy content
            charCount += strlen(buffer);
            lineCount++;

            // Word count calculation
            char* token = strtok(buffer, " ,.?!;:\""); // Tokenizing words
            while (token) {
                wordCount++;
                token = strtok(nullptr, " ,.?!;:\"");
            }
        }

        file.close();
        return true;
    }

    void displayStats() const {
        cout << "Total Lines: " << lineCount << endl;
        cout << "Total Words: " << wordCount << endl;
        cout << "Total Characters (including spaces and punctuation): " << charCount << endl;
    }

    ~TextProcessor() {
        for (int i = 0; i < lineCount; i++) {
            delete[] lines[i]; // Free memory for each line
        }
        delete[] lines; // Free main array
    }
};

int main() {
    const char* filename = "sample.txt";
    TextProcessor tp;

    if (tp.loadFile(filename)) {
        tp.displayStats();
    }

    return 0;
}
