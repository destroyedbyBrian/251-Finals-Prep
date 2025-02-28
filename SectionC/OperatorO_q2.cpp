// Question 3.2: Binary Operators (+, -) for a `Vector2D` class
/*
    Create a class `Vector2D` with `x` and `y` (double) components. Overload
    the `+` operator to add two `Vector2D` objects (component-wise addition)
    and the `-` operator to subtract two `Vector2D` objects.
*/

#include <iostream>


// =============  RENDITION #1 ❌  =============
class Vector2D {
public:
    double x, y;
    Vector2D () : x(0), y(0) {}
    Vector2D (double x, double y) : x(x), y(y) {}

    Vector2D operator+(const Vector2D& other) {
        return Vector2D(x + other.x && y + other.y);  // Use commas instead of logical operator
    }
    Vector2D operator-(const Vector2D& other) {
        return Vector2D(x - other.x && y - other.y); // Use commas instead of logical operator
    }
};

int main() {
    Vector2D v1(2, 2), v2(1, 3);
    Vector2D v3 = v1 + v2;
    Vector2D v4 = v1 - v3;

    std::cout << v3.x << ", " << v3.y << std::endl;
    std::cout << v4.x << ", " << v4.y << std::endl;
    return 0;
}


// =============  RENDITION #2 ✅  =============
class Vector2D {
public:
    double x, y;
    Vector2D () : x(0), y(0) {}
    Vector2D (double x, double y) : x(x), y(y) {}

    Vector2D operator+(const Vector2D& other) {
        return Vector2D(x + other.x, y + other.y); 
    }
    Vector2D operator-(const Vector2D& other) {
        return Vector2D(x - other.x, y - other.y); 
    }
};

int main() {
    Vector2D v1(2, 2), v2(1, 3);
    Vector2D v3 = v1 + v2;
    Vector2D v4 = v1 - v3;

    std::cout << v3.x << ", " << v3.y << std::endl;
    std::cout << v4.x << ", " << v4.y << std::endl;
    return 0;
}