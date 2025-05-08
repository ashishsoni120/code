#include <iostream>
#include <string>
using namespace std;
class Detail
{
    int Roll_Number;
    string Name;
    int Marks[3];
    double Average;

public:
    // Default constructor
    Detail()
    {
        Roll_Number = 0;
        Name = "Default Name";
        Marks[0] = Marks[1] = Marks[2] = 0;
    }

    // Parametrized constructor

    Detail(int Roll, string name, int m1, int m2, int m3)
    {
        Roll_Number = Roll;
        Name = name;
        Marks[0] = m1;
        Marks[1] = m2;
        Marks[2] = m3;
    }

    double Calculate_Average()
    {
        return (Marks[0] + Marks[1] + Marks[2]) / 3.0;
    }

    void Display_Data()
    {
        cout << "Roll Number : " << Roll_Number << endl;
        cout << "Name : " << Name<<endl;;
        cout << "Average Marks : " << Calculate_Average() << endl;
    }
};

int main()
{
    Detail student[3] = { Detail(),
                          Detail(143, "no name", 100, 100, 100),
                          Detail(145, "new name", 100, 100, 100) };

    for (int i = 0; i < 3; i++)
    {
        student[i].Display_Data();
    }
    return 0;
}