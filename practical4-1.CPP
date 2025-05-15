#include <iostream>
using namespace std;

class Base_Circle
{
    protected:
    float Radius;

public:
    void GetRadius()
    {
        cout << "Enter Radius: ";
        cin >> Radius;
    }
};

class Derived_Circle : public Base_Circle
{
public:
    float CalculateArea()
    {
        return 3.14 * Radius * Radius;
    }
};

int main()
{
    Derived_Circle D1;
    D1.GetRadius();
    cout << "Area of Circle is: " << D1.CalculateArea() << endl;
    return 0;
}
