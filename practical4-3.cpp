#include <iostream>
#include <queue>
using namespace std;

class fuel {
protected:
    string fueltype;
public:
    fuel(string FuelType) {
        fueltype = FuelType;
    }

    void displayfuel() const {
        cout << "Fuel Type : " << fueltype << endl;
    }
};

class brand  {
protected:
    string brandtype;
public:
    brand( string BrandType)   {
        brandtype = BrandType;
    }

    void displaybrand() const {
        cout << "Brand Type : " << brandtype << endl;
    }
};

class car : public fuel ,public brand {
protected:
    string model;
public:
    car(string FuelType, string BrandType, string Model) : fuel(FuelType),  brand(BrandType)
    {
        model = Model;
    }

    void displaycar() const {
        displayfuel();
        displaybrand();
        cout << "Car Model : " << model  << endl;
    }
};

int main() {
    queue<car> mycar;

    mycar.push(car("Petrol","TATA","Harrier"));
    mycar.push(car("Diesel","Toyota","ABC"));
    mycar.push(car("EV","Tesla","Tesla 1"));

    while(!mycar.empty())
    {
        car c = mycar.front();
        c.displaycar();
        cout<<"---------------------------------"<<endl;
        mycar.pop();
    }
    return 0;
}
