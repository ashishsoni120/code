#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Employee
{
    string Name;
    int Basic_Salary;
    int Bonus;

public:
    void Display()
    {
        cout << Name << endl
             << Basic_Salary << endl
             << Bonus << endl
             <<"Total Salary is  : $ "
             << Calculate_salary() << endl;
             cout<<"\n";
    }
    int Calculate_salary()
    {
        return Basic_Salary + Bonus;
    }
    Employee()
    {
        Name = ""; 
        Basic_Salary = 0;
        Bonus = 0;
    }

    Employee(string name, int basic_salary, int bonus)
    {
        Name = name; 
        Basic_Salary = basic_salary;
        Bonus = bonus;
    }
};

int main()
{
    vector<Employee> Emp1, Emp2, Emp3;
    Emp1.push_back(Employee("ABC", 5000, 500));
    Emp2.push_back(Employee("XYZ", 1000, 100));
    Emp3.push_back(Employee("PQR", 10000, 1000));

        Emp1[0].Display();

    for (auto &i: Emp2)
    {
        i.Display();
    }
    for (auto &i : Emp3)
    {
        i.Display();
    }
}