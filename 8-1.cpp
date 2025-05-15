#include <iostream>
#include <vector>
#include <algorithm> // For std::reverse
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> sequence(n);
    cout << "Enter the sequence: ";
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    // Using std::reverse
    reverse(sequence.begin(), sequence.end());

    cout << "Reversed sequence (using std::reverse): ";
    for (int num : sequence) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
