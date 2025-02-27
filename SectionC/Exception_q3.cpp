// Question 2.3: Throwing Exception Objects
/*
    Modify the `findCheapestBook` function from Question 1.2.  Instead of
    returning a default `Book` object for an empty array, throw a custom
    exception object of a new class `EmptyArrayException` (derived from
    `std::exception`).  Demonstrate how to catch this exception in a calling
    function.
*/

#include <iostream>
#include <stdexcept>
#include <string>

struct Book {
    std::string title;
    std::string author;
    int year;
    double price;
};

class EmptyArrayException : public std::exception {
    private:
        std::string errMessage;
    public:
        // Default constructor
        EmptyArrayException() : errMessage("Error") {}

        // Constructor
        EmptyArrayException(std::string e) : errMessage(e) {}

        std::string displayError() const {return errMessage;}
};


// =============  RENDITION #1 ❌  =============
Book findCheapestBook (const int (&bookList)) {  // Incorrect parameters
    try {  // Incorrect try/catch placement
        double cheapest = bookList[0];
        int index = 0;
    }
    catch (const EmptyArrayException& e) {
        std::cout << e.displayError() << std::endl;
    }
}

int main() {
    Book book1;
    std::cout << "Enter book title: ";
    std::cin.ignore();
    std::getline (std::cin, book1.title);

    std::cout << "Enter author's name: ";
    std::getline (std::cin, book1.author);

    std::cout << "Enter the book year: ";
    std::cin >> book1.year;
    std::cout << "Enter the book price: ";
    std::cin >> book1.price;

    int fakeList[1] = {};
    Book cheapestBk = findCheapestBook(fakeList);
    std::cout << cheapestBk.author << std::endl;
    return 0;
}


// =============  RENDITION #2 ✅  =============
Book findCheapestBook(const Book bookList[], int size) {
    if (size <= 0) {
        throw EmptyArrayException("Error: Empty array detected");
    } 
    Book cheapest = bookList[0];
    int index = 0;
    for (int i = 0 ; i < size; i++) {
        if (bookList[i].price < cheapest.price) {
            cheapest = bookList[i];
            index = i;
        }
    }
    return cheapest;
}

int main() {
    Book book1;
    std::cout << "Enter book title: ";
    std::cin.ignore();
    std::getline (std::cin, book1.title);

    std::cout << "Enter author's name: ";
    std::getline (std::cin, book1.author);

    std::cout << "Enter the book year: ";
    std::cin >> book1.year;
    std::cout << "Enter the book price: ";
    std::cin >> book1.price;

    Book bookList[1] = {book1};
    try {
        Book cheapestBook = findCheapestBook(bookList, 0);
        std::cout << cheapestBook.author << std::endl;
    }
    catch (const EmptyArrayException& e) {
        std::cout << e.displayError() << std::endl;
    }
    return 0;
}
