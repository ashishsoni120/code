#include <iostream>
#include <vector>
#include<chrono>
using namespace std;
using namespace chrono;
int total=0;
int addition(vector<int>& number,int z,int y)
{
    if(z==y)
    {
        return total;
    }
    total += number[z];
    addition(number,z+1,y);
}

int main()
{
    int size,sum,Z=0;
    cout << "How many numbers : ";
    cin >> size;

    vector<int> number(size);
    cout << "Enter the numbers: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> number[i];
    }
    auto start = high_resolution_clock::now(); // Start time measurement
    sum = addition(number,Z,size);
    auto stop = high_resolution_clock::now(); // Stop time measurement
    
    auto duration = duration_cast<microseconds>(stop - start); // Calculate duration

    cout << "The sum is: " << sum << endl;
    cout << "Execution time: " << duration.count() << " microseconds" << endl;

    return 0;
}