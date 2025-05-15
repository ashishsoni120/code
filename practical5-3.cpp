
#include <iostream>
#include <stack>
using namespace std;

class Complex
{
    int x, y;

public:
    // Default constructor
    Complex()
    {
        x = 0;
        y = 0;
    }

    Complex(int Xcord, int Ycord)
    {
        x = Xcord;
        y = Ycord;
    }

    Complex operator+(Complex C2)
    {
        Complex temp;
        temp.x = x + C2.x;
        temp.y = y + C2.y;
        return temp;
    }
    Complex operator-(Complex C2)
    {
        Complex temp;
        temp.x = x - C2.x;
        temp.y = y - C2.y;
        return temp;
    }

    int operator==(Complex temp)
    {
        if ((x == temp.x) && (y == temp.y))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void Showresult()
    {
        cout << "(x,y) = " << "(" << x << "," << y << ")" << endl;
    }
};

int main()
{
    stack<Complex> History;
    Complex C1(1, 2);
    Complex C2(3, 4);
    Complex C3;
    Complex C4;
    Complex C5(4, 6);

    // Complex number addtion
    C3 = C1 + C2;
    cout << "Addtion of complex number : ";
    C3.Showresult();
    History.push(Complex(C3));

    // Complex number substraction
    C4 = C2 - C1;
    cout << "Substraction of complex number : ";
    C4.Showresult();
    History.push(Complex(C4));

    // Complex number Equality
    bool x = (C5 == C3);
    if (x == 1)
    {
        cout << "Equality of complex number : ";
        C5.Showresult();
        History.push(Complex(C5));
    }
    else
    {
        cout << "no equlity.";
    }

    return 0;
}
