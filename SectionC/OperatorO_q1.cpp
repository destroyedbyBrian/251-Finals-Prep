// Question 3.1: Relational Operators (==, !=) for a `Point` class
/*
    Create a class `Point` with `x` and `y` (int) coordinates.  Overload the
    `==` and `!=` operators to compare two `Point` objects for equality.  Two
    points are equal if their x and y coordinates are both equal.
*/

#include <iostream>


// =============  RENDITION #1 ❌  =============
class Point {
public:
    int x, y;
    Point () : x(0), y(0) {}
    Point (int x, int y) : x(x), y(y) {}
    Point& operator==(const int& a, const int& b) {  // Should return bool, compare two Point objects not integers
        return a == b;  // Wrong return type
    }
    Point& operator!=(const int& a, const int& b) {  // Should return bool,  compare two Point objects not integers
        return a != b;  // Wrong return type
    }
}  // Missing semicolon

int main () {
    Point point1(2, 4);
    // Missing comparison
    return 0;
}


// =============  RENDITION #2 ❌  =============
class Point {
public:
    int x, y;
    Point () : x(0), y(0) {}
    Point (int x, int y) : x(x), y(y) {}
    bool Point.x& operator==(const Point.y&) {  // Invalid syntax, cannot use dot notation in this context
        return (Point.x == Point.y);  // Should compare two Point objects
    }
    bool Point.x& operator!=(const Point.y&) {
        return (Point.x != Point.y);
    }
};

int main () {
    Point point1(2, 4), point2(3, 3);
    point1.x != point1.y;  // Wrong comparison
    point2.x == point2.y;
    return 0;
}


// =============  RENDITION #3 ❌  =============
class Point {
public:
    int x, y;
    Point () : x(0), y(0) {}
    Point (int x, int y) : x(x), y(y) {}
    bool Point& operator==(const Point& other) {  // Invalid return type declaration
        return (Point == other);  // Should compare x & y coordinates separately
    }
    bool Point& operator!=(const Point& other) {
        return (Point != other);
    }
};
    
int main () {
    Point point1(2, 4), point2(3, 3);
    bool isequal = point1 == point2;
    bool isunequal = point1 != point2;
    return 0;
}


// =============  RENDITION #4 ✅  =============
class Point {
public:
    int x, y;
    Point () : x(0), y(0) {}
    Point (int x, int y) : x(x), y(y) {}
    bool operator==(const Point& other) const {  
        return (x == other.x && y == other.y);
    }
    bool operator!=(const Point& other) const {  
        return (x != other.x || y != other.y);
    }
};
    
int main () {
    Point point1(2, 4), point2(3, 3);
    bool isequal = point1 == point2;
    bool isunequal = point1 != point2;
    std::cout << std::boolalpha;
    std::cout << "Equal: " << isequal << std::endl;
    std::cout << "Unequal: " << isunequal << std::endl;
    return 0;
}


// =============  RENDITION #5 ✅  =============
class Point {
public:
    int x, y;
    Point () : x(0), y(0) {}
    Point (int x, int y) : x(x), y(y) {}
    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;
};

bool Point::operator==(const Point& other) const {  
    return (x == other.x && y == other.y);
}
bool Point::operator!=(const Point& other) const {  
    return (x != other.x || y != other.y);
}

int main () {
    Point point1(2, 4), point2(3, 3);
    bool isequal = point1 == point2;
    bool isunequal = point1 != point2;
    std::cout << std::boolalpha;
    std::cout << "Equal: " << isequal << std::endl;
    std::cout << "Unequal: " << isunequal << std::endl;
    return 0;
}