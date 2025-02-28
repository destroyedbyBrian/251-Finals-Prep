// Question 2.4: Re-throwing Exceptions and nested try-catch blocks
/*
    Create three functions:
    - validateData(int data): Throws a custom exception LowDataException if data < 10 and HighDataException if data > 100.
    - processData(int data): Calls validateData.  Catches LowDataException, prints a message, and *re-throws* the exception. Catches any other exception and prints "Data processing failed: generic error".
    - main(): Calls processData within a try-catch block.  Catches HighDataException, and prints a "Data out of upper bound error".  Catches LowDataException and prints "Data out of lower bound error". Catches all other exceptions. Demonstrates the exception handling.
*/

#include <iostream>
#include <string>
#include <stdexcept>


// =============  RENDITION #1 ❌  =============
class LowDataException : public std::exception {
    private:
        std::string errMessage;
    public:
        LowDataException() : errMessage("Low data error") {}
        LowDataException(std::string e) : errMessage(e) {}
        std::string displayError() const { return errMessage; }  // Override what() method
};

class HighDataException : public std::exception {
    private:
        std::string errMessage;
    public:
        HighDataException() : errMessage("High data error") {}
        HighDataException(std::string e) : errMessage(e) {}
        std::string displayError() const { return errMessage; }
};

void validateData (int data) {
    if (data < 10) {
        throw LowDataException("Error: low data detected");
    } else if (data > 100) {
        throw HighDataException("Error: high data detected");
    }
}

void processData(int data) { 
    validateData(data);  // Missing re-throwing logic
}

int main() {
    int data;
    try {
        std::cout << "Enter data size: ";
        std::cin >> data;
        if ( data < 10 ) {
            throw LowDataException("Data out of lower bound error");
        } else if ( data > 100) {
            throw HighDataException("Data out of upper bound error");
        }
        processData(data);
    }
    catch(const std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}


// =============  RENDITION #2 ✅  =============
class LowDataException : public std::exception {
    private:
        std::string errMessage;
    public:
        LowDataException() : errMessage("Low data error") {}
        LowDataException(std::string e) : errMessage(e) {}
        const char* what() const noexcept override {
            return errMessage.c_str();
        }
};

class HighDataException : public std::exception {
    private:
        std::string errMessage;
    public:
        HighDataException() : errMessage("High data error") {}
        HighDataException(std::string e) : errMessage(e) {}
        const char* what() const noexcept override {
            return errMessage.c_str();
        }
};

void validateData (int data) {
    if (data < 10) {
        throw LowDataException("Low data detected");
    } else if (data > 100) {
        throw HighDataException("High data detected");
    }
}

void processData(int data) {
    try {
        validateData(data);
    }
    catch (const LowDataException& e) {
        std::cout << "Data Error: " << e.what() << std::endl;
        throw;
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

int main() {
    int data;
    try {
        std::cout << "Enter data size: ";
        std::cin >> data;
        processData(data);
    }
    catch (const LowDataException& e) {
        std::cout << "Data out of lower bound error" << std::endl;
    }
    catch (const HighDataException& e) {
        std::cout << "Data out of upper bound error" << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}

