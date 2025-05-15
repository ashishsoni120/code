#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class DirectoryManager {
private:
    map<string, vector<string>> directories; // Maps folder names to file lists

public:
    // Function to create a new folder
    void createFolder(const string& folderName) {
        if (directories.find(folderName) == directories.end()) {
            directories[folderName] = vector<string>(); // Initialize empty file list
            cout << "Folder '" << folderName << "' created successfully.\n";
        } else {
            cout << "Folder already exists.\n";
        }
    }

    // Function to add a file to an existing folder
    void addFile(const string& folderName, const string& fileName) {
        if (directories.find(folderName) != directories.end()) {
            directories[folderName].push_back(fileName);
            cout << "File '" << fileName << "' added to folder '" << folderName << "'.\n";
        } else {
            cout << "Folder '" << folderName << "' does not exist. Create it first.\n";
        }
    }

    // Function to display the directory structure in sorted order
    void displayStructure() {
        cout << "\nDirectory Structure:\n";
        for (const auto& folder : directories) {
            cout << folder.first << ":\n";
            for (const auto& file : folder.second) {
                cout << "  - " << file << endl;
            }
        }
    }
};

int main() {
    DirectoryManager dm;
    int choice;
    string folderName, fileName;

    do {
        cout << "\nDirectory Management System\n";
        cout << "1. Create Folder\n2. Add File to Folder\n3. Display Directory Structure\n4. Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter folder name: ";
                getline(cin, folderName);
                dm.createFolder(folderName);
                break;
            case 2:
                cout << "Enter folder name: ";
                getline(cin, folderName);
                cout << "Enter file name: ";
                getline(cin, fileName);
                dm.addFile(folderName, fileName);
                break;
            case 3:
                dm.displayStructure();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
