// Question 1.1: Basic Struct and Function
/*
    Define a struct named `Book` with members: `title` (string), `author` (string),
    `year` (int), and `price` (double).  Write a function `printBook` that takes
    a `Book` struct as input (by value) and prints its details in a nicely formatted way.
*/

#include <iostream>
#include <sstream>
#include <string>

// =============  RENDITION #1 ❌  =============
struct Book = {  // Wrong syntax
    std::string title;
    std::string author;
    int year;
    double price;
}  // Missing semicolon

string printBook : Book () {  // Missing std::string
    std::cin >> Book.title;
    std::cin >> Book.author;
    std::cin >> Book.year;
    std::cin >> Book.price;

    ostream oss;  // std::ostringstream

    oss << "Book Title: " << Book.title;  // .str()

    no return string statement
}


// =============  RENDITION #2 ❌  =============
struct Book {
    std::string title;
    std:: string author;
    int year;
    double price;
}  // missing semicolon

string printBook() {  // std::string
    std::cin >> Book.title;

    // no return string statement
}


// =============  RENDITION #3 ❌  =============
struct Book {
    std::string title;
    std::string author;
    int year;
    double price;
};

std::string printBook(&Book book) {  // Pass Book object by reference -> Book& book
    std::cin >> book.title;
    std::cin >> book.author;
    std::cin >> book.year;
    std::cin >> book.price;

    std::ostringstream oss;

    oss << book.title
        << book.author
        << book.year
        << book.price;

    return oss.str()
}

// =============  RENDITION #4 ✅  =============

struct Book {
    std::string title;
    std::string author;
    int year;
    double price;
};

std::string printBook(Book& book) {
    std::cout << "Enter the book title: ";
    std::cin >> book.title;
    std::cout << "Enter the author's name: ";
    std::cin >> book.author;
    std::cout << "Enter the book year: ";
    std::cin >> book.year;
    std::cout << "Enter the book price: ";
    std::cin >> book.price;

    std::ostringstream oss;

    oss << "Book title: " << book.title << "\n"
        << "Book author: " << book.author << "\n"
        << "Book year: " << book.year << "\n"
        << "Book price: " << book.price; 

    return oss.str();
}

// =============  Rendition #5: OVERLOADING ✅  =============
struct Book {
    std::string title;
    std::string author;
    int year;
    double price;
};

std::ostream& operator<<(std::ostream& oss, const Book& book) {
    oss << "Book title: " << book.title << "\n"
        << "Book author: " << book.author << "\n"
        << "Book year: " << book.year << "\n"
        << "Book price: " << book.price; 

    return oss;
}

int main() {
    Book book;

    std::cout << "Enter the book title: ";
    std::cin >> book.title;
    std::cout << "Enter the author's name: ";
    std::cin >> book.author;
    std::cout << "Enter the book year: ";
    std::cin >> book.year;
    std::cout << "Enter the book price: ";
    std::cin >> book.price;

    std::cout << book << std::endl;
    return 0;
}