
#include <iostream>
using namespace std;

class DynamicArray
{
    int *Data;
    int Capacity;
    int Size;

public:
    DynamicArray(int Capacity)
    {
        this->Capacity = Capacity;
        Size = 0;
        Data = new int[Capacity];
    }
    ~DynamicArray()
    {
        delete[] Data;
    }

    void insert(int value)
    {
        if (Size == Capacity)
        {
            cout << "Array is full...." << endl;
        }
        else
        {
            Data[Size++] = value;
        }
    }

    void PrintArray() const
    {
        for (int i = 0; i < Size; i++)
        {
            cout << "Element [" << i << "] -> " << Data[i] << endl;
        }
    }

    void Remove(int index)
    {
        for (int i = index; i < Size - 1; i++)
        {
            Data[i] = Data[i + 1];
        }
    }
};

int main()
{
    DynamicArray Arr(4);
    Arr.insert(10);
    Arr.insert(20);
    Arr.insert(30);

    Arr.Remove(1);
    Arr.PrintArray();
    return 0;
}
