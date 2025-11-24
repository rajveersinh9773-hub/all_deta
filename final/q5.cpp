#include <iostream>
using namespace std;

class vehicle {
public:
    virtual void startEngine() = 0;
    virtual void drive() = 0;
};

class Car : public vehicle {
public:
    void startEngine() override {
        cout << "Car engine started." << endl;
    }
    void drive() override {
        cout << "Car is driving..." << endl;
    }
};

class Bike : public vehicle {
public:
    void startEngine() override {
        cout << "Bike engine started." << endl;
    }
    void drive() override {
        cout << "Bike is driving..." << endl;
    }
};

int main() {
    
    Car c1;
    
    c1.startEngine();
    c1.drive();
    
    Bike b1;

    b1.startEngine();
    b1.drive();
    return 0;
}
