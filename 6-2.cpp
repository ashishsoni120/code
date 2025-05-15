
#include <iostream>
using namespace std;

class Point
{
    int x, y;

public:
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    Point *move(int &dx, int &dy)
    {
        x += dx;
        y += dy;
        return this;
    }

    void Print() const
    {
        cout<<"Updated Position is : (x,y) = " << "(" << x <<" , " << y << ")"<<endl;
    }
};
int main()
{
    int x=5,y=10;
    Point *p = new Point(x, y);
    cout<<"Initial Position is : (x,y) = " << "(" << x <<" , " << y << ")"<<endl;

    int dx1, dx2, dy1, dy2;

    cout << "Enter dx1 & dy1 -> ";
    cin >> dx1 >> dy1;

    cout << "Enter dx2 & dy2 -> ";
    cin >> dx2 >> dy2;

    p->move(dx1, dy1)->move(dx2, dy2);

    p->Print();
    return 0;
}
