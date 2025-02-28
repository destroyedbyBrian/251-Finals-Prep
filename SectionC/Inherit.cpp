// Question 4.2: Inheritance
/*
    Create a base class `Shape` with a virtual function `getArea()` that returns
    a double.  Create derived classes `Circle` (with a `radius`) and `Rectangle`
    (with `width` and `height`).  Override `getArea()` in each derived class to
    calculate the correct area.
*/

#include <iostream>


// =============  RENDITION #1 ❌  =============
class Shape {
public:
    virtual double getArea() {}  // Should return value or be marked as pure virtual
};

class Circle : public Shape {
public:
    double radius;
    Circle () : radius(0) {}
    Circle (double r) : radius(r) {}
};


class Rectangle : public Shape {
public:
    double height, width;
    Rectangle () : height(0), width(0) {}
    Rectangle (double h, double w) : height(h), width(w) {}
};

double Circle::getArea override () {  // Wrong syntax, should not be outside scope
    return (3.142 * (radius * radius));
}

double Rectangle::getArea override () {  // Wrong syntax, should not be outside scope
    return (height * width);
}

int main() {
    Circle circle1(5.5);
    double areaofCircle = circle1.getArea();
    Rectangle rectangle1(4.4, 3.3);
    double areaofRect = rectangle1.getArea();

    std::cout << areaofCircle << std::endl;
    std::cout << areaofRect << std::endl;
    return 0;
}


// =============  RENDITION #2 ✅  =============
class Shape {
public:
    virtual double getArea() { return 0.0; }
};

class Circle : public Shape {
public:
    double radius;
    Circle () : radius(0) {}
    Circle (double r) : radius(r) {}
    double getArea () override {  
        return (3.142 * (radius * radius));
    }
};

class Rectangle : public Shape {
public:
    double height, width;
    Rectangle () : height(0), width(0) {}
    Rectangle (double h, double w) : height(h), width(w) {}

    double getArea () override {  
        return (height * width);
    }
    
};

int main() {
    Circle circle1(5.5);
    double areaofCircle = circle1.getArea();
    Rectangle rectangle1(4.4, 3.3);
    double areaofRect = rectangle1.getArea();

    std::cout << areaofCircle << std::endl;
    std::cout << areaofRect << std::endl;
    return 0;
}