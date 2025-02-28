// Question 3.3: IO Operators (<<, >>) for a `Complex` class
/*
    Create a class `Complex` representing complex numbers with `real` and
    `imaginary` (double) parts.  Overload the `<<` (insertion) operator to
    output a `Complex` number in the format "a + bi" (or "a - bi" if
    imaginary is negative), and `>>` to read two double inputs for real and imaginar parts of the Complex number.
*/

#include <iostream>
#include <sstream>

class Complex {
public:
    double real, imaginary;
    Complex () : real(0), imaginary(0) {}
    Complex (double r, double i) : real(r), imaginary(i) {}
};


// =============  RENDITION #1 ❌  =============
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    if (c.imaginary < 0) {  
        os << c.real << "-" << c.imaginary;  // Missing 'i'
        return os;
    } 
    os << c.real << "+" << c.imaginary;  // Missing 'i'
    return os;
}

std::istream& operator>>(std::istream& is, Complex& c) {
    std::cout << "Enter real number value";  // Wrong implementation
    std::cin >> c.real;
    std::cout << "Enter imaginary number value";
    std::cin >> c.imaginary;

    // Missing return input stream
}

int main() {
    Complex c1;
    std::cin >> c1;
    std::cout << c1 << std::endl;
    return 0;
}


// =============  RENDITION #2 ❌  =============
std::ostream& operator<<(std::ostream& os, Complex& c) {  // const Complex parameter
    if (c.imaginary < 0) {
        os << c.real << " " << -c.imaginary << "i";
        return os;  // Duplicated os statements
    }
    os << c.real << " " << +c.imaginary << "i";  // Redundant + operator
    return os;
}

std::istream& operator>>(std::istream& is, Complex& c) { 
    is >> c.real >> c.imaginary;
    return is;
}

int main() {
    Complex c1;
    std::cin >> c1;
    std::cout << c1 << std::endl;
    return 0;
}


// =============  RENDITION #3 ✅  =============
std::ostream& operator<<(std::ostream& os, const Complex& c) {  
    if (c.imaginary < 0) {
        os << c.real << c.imaginary << "i";
    } else {
        os << c.real << "+" << c.imaginary << "i";  
    }
    return os;
}

std::istream& operator>>(std::istream& is, Complex& c) { 
    is >> c.real >> c.imaginary;
    return is;
}

int main() {
    Complex c1;
    std::cout << "Enter real and imaginary parts: ";
    std::cin >> c1;
    std::cout << "Complex number: " << c1 << std::endl;
    return 0;
}