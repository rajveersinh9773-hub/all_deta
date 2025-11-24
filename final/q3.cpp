
#include <iostream>
using namespace std;

class Shape {
private:

    float area;
public:
    
    void setArea(float a) {
        area = a;
    }

    float getArea() {
        return area;
    }
};
class Circle : public Shape {
private:
    float radius;

public:
    Circle(float r) {
        radius = r;
    }

    void calculateArea() {
        float a = 3.14 * radius * radius;
        setArea(a);
    }
};
class Rectangle : public Shape {
private:
    float length, width;

public:
    Rectangle(float l, float w) {
        length = l;
        width = w;
    }

    void calculateArea() {
        float a = length * width;
        setArea(a);
    }
};
int main() {
    Circle c(5);
    c.calculateArea();
    cout << "Circle Area: " << c.getArea() << endl;

    Rectangle r(4, 6);
    r.calculateArea();
    cout << "Rectangle Area: " << r.getArea() << endl;

    return 0;
}
