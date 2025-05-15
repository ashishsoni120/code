#include <iostream>
using namespace std;

class Calculator
{
public:
    int add(int a, int b)
    {
        int result = a + b;
        displayResult("add(int, int)", result);
        return result;
    }

    float add(float a, float b)
    {
        float result = a + b;
        displayResult("add(float, float)", result);
        return result;
    }

    double add(double a, double b)
    {
        double result = a + b;
        displayResult("add(double, double)", result);
        return result;
    }

    double add(int a, double b)
    {
        double result = a + b;
        displayResult("add(int, double)", result);
        return result;
    }

    double add(float a, int b)
    {
        double result = a + b;
        displayResult("add(float, int)", result);
        return result;
    }

private:
    void displayResult(const string &operation, double result)
    {
        cout << operation << " = " << result << endl;
    }
};
int main()
{
    Calculator calc;

    calc.add(5, 10);
    calc.add(3.5f, 2.5f);
    calc.add(2.1, 3.9);
    calc.add(7, 4.3);
    calc.add(1.2f, 3);

    return 0;
}
