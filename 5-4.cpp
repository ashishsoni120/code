#include <iostream>
using namespace std;

class Fahrenheit;

class Celcius {
    float celcius;

public:
    Celcius(float celcius) {
        this->celcius = celcius;
    }

    float Get_celcius() const  {
        return celcius;
    }

    friend int operator==(const Celcius& c, const Fahrenheit& f);
};

class Fahrenheit {
    float fahrenheit;

public:
    Fahrenheit(float fahrenheit) {
        this->fahrenheit = fahrenheit;
    }

    float Get_fahrenheit() const{
        return fahrenheit;
    }

    float tocelcius() const {
        return (fahrenheit - 32) * 5 / 9;
    }

    friend int operator==(const Celcius& c, const Fahrenheit& f);
};

int operator==(const Celcius& c, const Fahrenheit& f) {
    float c1 = c.Get_celcius();
    float c2 = f.tocelcius();

    if (c1 == c2) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    Fahrenheit F1(80.6); // ≈ 27°C
    Celcius C1(27.0);

    bool x = (C1 == F1);
    if (x == 1) {
        cout << "temperatures are equal." << endl;
    } else {
        cout << "temperatures are not equal." << endl;
    }

    return 0;
}
