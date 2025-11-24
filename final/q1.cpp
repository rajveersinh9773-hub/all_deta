#include <iostream>
using namespace std;

class Laptop {
private:
    string name;
    float price;
    string processor;

public:

    Laptop(string n, float p, string pr) {
        name = n;
        price = p;
        processor = pr;
    }
    void display() {
        cout << "Laptop Name: " << name << endl;
        cout << "Price: " << price << endl;
        cout << "Processor: " << processor << endl;
    }
};

int main() {
    Laptop l1("HP Pavilion", 55000, "Intel i5");
    Laptop l2("Dell Inspiron", 62000, "Intel i7");

    l1.display();
    cout << endl;
    l2.display();

    return 0;
}
