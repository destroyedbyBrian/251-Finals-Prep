// Question 2.2: Custom Exception Class
/*
    Create a custom exception class called `InvalidInputException` that inherits
    from `std::exception`.  It should have a constructor that takes an error
    message (string) as input.  Write a function `getPositiveInteger` that
    prompts the user for a positive integer.  If the user enters a non-positive
    number, throw an `InvalidInputException` with a descriptive message.  Use
    a `try-catch` block in the `main` function to handle this exception.
*/

#include <iostream>
#include <stdexcept>
#include <string>


// =============  RENDITION #1 ❌  =============
class InvalidInputException : std::exception {  // Inheritance should be public
    public:
        std::string errorMessage;  // Private 
        // Default constructor
        InvalidInputException() : errorMessage(" ") {}  // Default message

        // Constructor
        InvalidInputException(std::string e) : errorMessage(e) {}
};

int getPositiveValue() {
    int val;
    std::cout << "Enter a positive value: ";
    std::cin >> val;

    // Check and throw here
    return val;
}

int main() {
    try {
        int value = getPositiveValue();
        if (value < 0) {
            throw "Negative value detected";  // Throw InvalidInputException object instead of string literal
        }
        return 0;
    }
    catch (InvalidInputException errMsg &e) {  // Syntax error
        std::cout << e.errorMessage << std::endl;
    }
}


// =============  RENDITION #2 ✅  =============
class InvalidInputException : public std::exception {
    private:
        std::string errMessage;
    public:
    // Default Constructor
    InvalidInputException() : errMessage("Invalid input error") {}

    //Constructor
    InvalidInputException(std::string e) : errMessage(e) {}

    std::string displayError() const {
        return errMessage;
    }
};

int getPositiveValue() {
    int val;
    std::cout << "Enter a positive value: ";
    std::cin >> val;

    if (val < 0) {
        throw InvalidInputException("Value must be positive");
    }
    return val;
}

int main() {
    try {
        int value = getPositiveValue();
        std::cout << value << std::endl;
    }
    catch (const InvalidInputException& e) {
        std::cout << e.displayError() << std::endl;
    }
    return 0;
}