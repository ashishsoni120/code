#include <iostream>
using namespace std;
long int superdigit(int n)
{
    int Sum = 0, Sum1 = 0;

    while (n > 0)
    {
        Sum = n % 10;
        Sum1 += Sum;
        n = n / 10;
    }
    if (Sum1 < 10 && Sum1 > 0)
    {
        return Sum1;
    }
    else
    {
        superdigit(Sum1);
    }
}

int main()
{
    long int num, Num;
    int k, temp, temp1 = 0;

    cout << "Enter the Number you want to find super digit :  ";
    cin >> num;

    cout << "Enter number of time to concate the number : ";
    cin >> k;

    while (num > 0)
    {
        temp = 0;
        temp = num % 10;
        temp1 += temp * k;
        num = num / 10;
    }

    if (temp1 < 10 && temp1 > 0)
    {
        cout << "Super Digit is : " << temp1 << endl;
    }
    else
    {
        Num = superdigit(temp1);
    }
    cout << "Super Digit is : " << Num << endl;
    return 0;
}