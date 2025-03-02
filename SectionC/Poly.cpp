// Question 4.3: Polymorphism (Method Overriding and Dynamic Binding)
/*
    Create an array of `Shape*` pointers.  Populate the array with a mix of
    `Circle` and `Rectangle` objects.  Write a loop that iterates through
    the array and calls `getArea()` on each object.  Demonstrate that the
    correct `getArea()` method is called for each object, even though the
    pointers are all of type `Shape*`. Show the difference between *static* binding using Shape objects, and dynamic binding using Shape* pointers.
*/

#include <iostream>

class Shape {
public:
    virtual double getArea() { return 0.0; }
    virtual ~Shape() {}
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
    // Static binding example (using objects)
    Shape shape;
    Circle circle1(5.5);
    double areaofCircle = circle1.getArea();
    Rectangle rectangle1(4.4, 3.3);
    double areaofRect = rectangle1.getArea();

    std::cout << "Shape area: " << shape.getArea() << std::endl;
    std::cout << "Circle area: " << circle1.getArea() << std::endl;
    std::cout << "Rectangle area: " << rectangle1.getArea() << std::endl;
    
    // Dynamic binding example (using pointers)
    Shape* shapes[4];  // Array of pointers

    shapes[0] = new Circle(2.0);
    shapes[1] = new Rectangle(3.0, 4.0);
    shapes[2] = new Circle(1.0);
    shapes[3] = new Rectangle(5.0, 2.0);

    for (Shape* shape : shapes) {
        std::cout << "Shape area: " << shape->getArea();
    }

    // Clean up memory
    for(int i = 0; i < 4; i++) {
        delete shapes[i];
    }

    return 0;
}

