#include <iostream>
using namespace std;

// Function to merge two sorted arrays into a new dynamically allocated array
int* mergeSortedArrays(int* arr1, int size1, int* arr2, int size2, int& mergedSize) {
    mergedSize = size1 + size2;
    int* mergedArray = new int[mergedSize];

    int i = 0, j = 0, k = 0;

    // Merge while both arrays have elements
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            mergedArray[k++] = arr1[i++];
        } else {
            mergedArray[k++] = arr2[j++];
        }
    }

    // Copy remaining elements from arr1
    while (i < size1) {
        mergedArray[k++] = arr1[i++];
    }

    // Copy remaining elements from arr2
    while (j < size2) {
        mergedArray[k++] = arr2[j++];
    }

    return mergedArray;
}

int main() {
    int size1, size2;

    // Read sizes of both arrays
    cout << "Enter size of first sorted array: ";
    cin >> size1;
    int* arr1 = new int[size1];
    cout << "Enter elements of first sorted array: ";
    for (int i = 0; i < size1; i++) {
        cin >> arr1[i];
    }

    cout << "Enter size of second sorted array: ";
    cin >> size2;
    int* arr2 = new int[size2];
    cout << "Enter elements of second sorted array: ";
    for (int i = 0; i < size2; i++) {
        cin >> arr2[i];
    }

    int mergedSize;
    int* mergedArray = mergeSortedArrays(arr1, size1, arr2, size2, mergedSize);

    // Display merged sorted array
    cout << "Merged sorted array: ";
    for (int i = 0; i < mergedSize; i++) {
        cout << mergedArray[i] << " ";
    }
    cout << endl;

    // Clean up dynamically allocated memory
    delete[] arr1;
    delete[] arr2;
    delete[] mergedArray;

    return 0;
}
