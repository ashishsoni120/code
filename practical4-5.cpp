#include<iostream>
#include<vector>
using namespace std;

class Student
{
protected:
    float marks;

public:
    void Set_Marks(float m)
    {
        marks = m;
    }

    virtual string computegrade() = 0;

    virtual ~Student() {}  // Provide definition for destructor
};

class Undergraduate : public Student
{
public:
    string computegrade() override
    {
        if (marks >= 85) return "A";
        else if (marks >= 70) return "B";
        else if (marks >= 50) return "C";
        else return "F";
    }
};

class Postgraduate : public Student
{
public:
    string computegrade() override
    {
        if (marks >= 90) return "A";
        else if (marks >= 75) return "B";
        else if (marks >= 60) return "C";
        else return "F";
    }
};

int main()
{
    vector<Student*> Students;

    int n;
    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int type;
        float m;
        cout << "Enter student type (1 for UG, 2 for PG): ";
        cin >> type;

        cout << "Enter marks: ";
        cin >> m;

        Student* s = nullptr;

        if (type == 1)
        {
            s = new Undergraduate();
        }
        else if (type == 2)
        {
            s = new Postgraduate();
        }
        else
        {
            cout << "Invalid Student type. Skipping...\n";
            continue;
        }

        s->Set_Marks(m);
        Students.push_back(s);
    }

    cout << "\nStudent Grades:\n";
    for (size_t i = 0; i < Students.size(); ++i)
    {
        cout << "Student " << i + 1 << ": " << Students[i]->computegrade() << "\n";
    }

    // Clean up dynamically allocated memory
    for (Student* s : Students)
    {
        delete s;
    }

    return 0;
}
