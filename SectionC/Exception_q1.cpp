// Question 2.1: Basic try-catch
/*
    Write a function `safeDivide` that takes two integers (numerator and
    denominator) as input.  Use a `try-catch` block to handle the potential
    `std::runtime_error` that can occur if the denominator is zero.  If a
    division-by-zero occurs, catch the exception and print an error message.
    Otherwise, return the result of the division.
*/

#include <iostream>
#include <stdexcept>


// =============  RENDITION #1 ❌  =============
double safeDivide() {
    try {
        double numerator, denominator, result;
        std::cout << "Enter numerator value: ";
        std::cin >> numerator;
        std::cout << "Enter denominator value: ";
        std::cin >> denominator;
        result = numerator / denominator;
        return result;
    }
    catch (denominator == 0) {  // Need to catch a specific exception type
        std::cout << "Division  by zero error" << std::endl;
    }
    
}

int main() {
    safeDivide();
    return 0;
}


// =============  RENDITION #2 ❌  =============
double safeDivide() {  // Needs to take in two integer values
    try {
        double numerator, denominator, result;
        std::cout << "Enter numerator value: ";
        std::cin >> numerator;
        std::cout << "Enter denominator value: ";
        std::cin >> denominator;

        if (denominator == 0) {
            throw denominator;
        }
        result = numerator / denominator;
        return result;
    }
    catch (double denominator) {  // Need to catch a specific exception type
        std::cout << "Division by zero error detected, denominator cannot be" << denominator << std::endl;
    }
}

int main() {
    safeDivide();
    return 0;
}


// =============  RENDITION #3 ❌  =============
double safeDivide(int& numerator, int& denominator) {
    try {
        if (denominator == 0) {
            throw std::runtime_error(denominator);  // Error constructor takes a string message
        }
        return type_cast<double> result = numerator / denominator;  // Incorrect syntax
    }
    catch (std::runtime_error &e) {
        std::cout << "Divison by zero error detected, denominator cannot be" << denominator << std::endl;
        return 1;
    }
}

int main() {
    int numerator, denominator;
    std::cout << "Enter numerator value: ";
    std::cin >> numerator;
    std::cout << "Enter denominator value: ";
    std::cin >> denominator;
    
    double result = safeDivide(numerator, denominator);
    std::cout << "Result: " << result << std::endl;
    return 0;
}


// =============  RENDITION #4 ✅  =============
double safeDivide(int numerator, int denominator) {
    try {
        if (denominator == 0) {
            throw std::runtime_error("Division by zero error");
        }
        return static_cast<double> (numerator) / denominator; 
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        return 0;
    }
}

int main() {
    int numerator, denominator;
    std::cout << "Enter numerator value: ";
    std::cin >> numerator;
    std::cout << "Enter denominator value: ";
    std::cin >> denominator;
    
    double result = safeDivide(numerator, denominator);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
