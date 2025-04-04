#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual void calculateArea() = 0;
};

class Rectangle : public Shape {
private:
    double length, breadth;

public:
    Rectangle(double l, double b) : length(l), breadth(b) {}

    void calculateArea() override {
        cout << "Rectangle Area: " << length * breadth << endl;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    void calculateArea() override {
        cout << "Circle Area: " << M_PI * radius * radius << endl;
    }
};

int main() {
    Shape *shape1 = new Rectangle(10, 5);
    Shape *shape2 = new Circle(7);

    shape1->calculateArea();
    shape2->calculateArea();

    delete shape1;
    delete shape2;

    return 0;
}
