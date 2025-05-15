#include <iostream>
#include <string>
using namespace std;

class Employee
{
protected:
    string name;
    int age;

public:
    Employee(string Name, int Age)
    {
        name = Name;
        age = Age;
    }

    void Get_Detail()
    {
        cout << "Name of the Employee is: " << name << endl;
        cout << "Age of the Employee is: " << age << endl;
    }
};

class Emp_Id : public Employee
{
protected:
    int Emp_id;

public:
    Emp_Id(string Name, int Age, int id) : Employee(Name, Age)
    {
        Emp_id = id;
    }

    void GetEmpId()
    {
        cout << "Employee ID is: " << Emp_id << endl;
    }
};

class Manager : public Emp_Id
{
    string Department;

public:
    Manager(string Name, int Age, int ID, string dept) : Emp_Id(Name, Age, ID)
    {
        Department = dept;
    }

    void GetDepartment()
    {
        cout << "Department of the employee is: " << Department << endl;
    }
};

int main()
{
    Manager M1("ashish", 18, 1, "ce");
    M1.GetDepartment();
    M1.Get_Detail();
    M1.GetEmpId();

    return 0;
}
