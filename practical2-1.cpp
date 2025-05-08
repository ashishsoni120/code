#include <iostream>
using namespace std;
class Area
{
    float Length;
    float Width;

public:
    setDimensions()
    {
        cout << "Enter length & width : ";
        cin >> Length >> Width;
    }

    CalculateArea()
    {
        float Area = Length * Width;
        cout << "Area of Rectangel is : " << Area;
    }

    CalculatePerimeter()
    {
        float Perimeter = 2 * (Length + Width);
        cout << "\nPerimeter of Rectangel is : " << Perimeter;
    }
} Detail[5];

int main()
{
    int Number;
    cout << "Enter how many number of rectangel you want : ";
    cin >> Number;

    for (int i = 0; i < Number; i++)
    {
        cout << "\nEnter Detail of  " << i + 1 << " rectangle : " << endl;
        Detail[i].setDimensions();   
        Detail[i].CalculateArea();
        Detail[i].CalculatePerimeter();
    }
}