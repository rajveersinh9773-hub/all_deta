#include <iostream>
using namespace std;

class Shape {
public:
    virtual void displayDetails() {
        cout << "This is a shape." << endl;
    }
};
class Circle : public Shape {
public:
    void displayDetails() override {
        cout << "This is a Circle." << endl;
    }
};
class Rectangle : public Shape {
public:
    void displayDetails() override {
        cout << "This is a Rectangle." << endl;
    }
};
int main() {
    Shape* arr[3];

    arr[0] = new Shape();
    arr[1] = new Circle();
    arr[2] = new Rectangle();

    for (int i = 0; i < 3; i++) {
        arr[i]->displayDetails();
    }

    return 0;
}
