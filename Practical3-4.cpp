#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
T FindMax(vector<T> &Vec)
{
    T maxValue = Vec[0];
    for (const auto &n : Vec)
    {
        if (n > maxValue)
        {
            maxValue = n;
        }
    }
    return maxValue;
}

template <typename T>
void reverseVec(vector<T> &vec) // Change return type to void
{
    reverse(vec.begin(), vec.end());
}

template <typename T>
void printVector(const vector<T> &vec)
{
    for (const auto &N : vec)
    {
        cout << N << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> intVec;
    intVec = {10, 20, 30};
    cout << "Max of 10, 20, 30 : " << FindMax(intVec) << endl;

    vector<float> floatVec;
    floatVec = {1.2, 2.2, 3.2};
    cout << "Max of 1.2, 2.2, 3.2 : " << FindMax(floatVec) << endl;

    vector<char> charVec;
    charVec = {'A', 'B', 'C'};
    cout << "Max of 'A', 'B', 'C' : " << FindMax(charVec) << endl;

    cout << "After reversing the vectors:" << endl;

    reverseVec(intVec);
    cout << "Reversed 10, 20, 30 : ";
    printVector(intVec);

    reverseVec(floatVec);
    cout << "Reversed 1.2, 2.2, 3.2 : ";
    printVector(floatVec);

    reverseVec(charVec);
    cout << "Reversed 'A', 'B', 'C' : ";
    printVector(charVec);

    return 0;
}