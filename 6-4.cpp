#include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "Base constructor\n"; }
    virtual ~Base() { cout << "Base destructor\n"; } // Making destructor virtual
};

class Derived : public Base {
private:
    int* data;
public:
    Derived() {
        data = new int[10]; // Dynamic allocation
        cout << "Derived constructor\n";
    }

    ~Derived() {
        delete[] data; // Proper deallocation
        cout << "Derived destructor\n";
    }
};

int main() {
    Base* obj = new Derived(); // Object created dynamically
    delete obj; // Correctly calls Derived destructor because Base destructor is virtual

    return 0;
}
