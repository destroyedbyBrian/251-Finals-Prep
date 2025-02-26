// Question 1.2: Array of Structs and Function
/*
    Write a function `findCheapestBook` that takes an array of `Book` structs
    (and the array's size) as input and returns the `Book` struct representing the
    book with the lowest price. If the array is empty, return a `Book` object with
    default values (e.g., empty strings, 0 for year and price).
*/

#include <iostream>
#include <string>

struct Book {
    std::string title;
    std::string author;
    int year;
    double price;
};


// =============  RENDITION #1 ❌  =============
Book findCheapestBook(const &bookCollection[]) {  // Array size not declared
    double min = 0;
    if (bookCollection) {
        double min = bookCollection[0];  // Price is initialised
        for (const auto& book : bookCollection[]) {
            if (book.price  < min) {
                min = book.price
            }
        }
    }
    for (const auto& book : bookCollection[]) {
        if (min == book.price) {
            return book;
        }
    }
}

int main() {
    Book book1, book2;

    std::cout << "Enter the book title: ";
    std::cin >> book1.title;
    std::cout << "Enter the author's name: ";
    std::cin >> book1.author;
    std::cout << "Enter the book year: ";
    std::cin >> book1.year;
    std::cout << "Enter the book price: ";
    std::cin >> book1.price;

    std::cout << "Enter the book title: ";
    std::cin >> book2.title;
    std::cout << "Enter the author's name: ";
    std::cin >> book2.author;
    std::cout << "Enter the book year: ";
    std::cin >> book2.year;
    std::cout << "Enter the book price: ";
    std::cin >> book2.price;

    bookCollection[] = {book1, book2}  // No declared array type, No defined array size 

    return 0;
}


// =============  RENDITION #2 ❌  =============
Book findCheapestBook(const Book& bookCollection[2]) {  // Incorrect parameter
    if (bookCollection[2].empty()) {  // Out of bounds
        return Book;  // Create an instance of Book object
    }
    else {
        double cheapest = bookCollection[0].price;
        for (const auto& book : bookCollection[2]) {  // Out of bounds
            if (book.price < cheapest) {
                cheapest = book.price;
            }
        }
    }
    // missing return statement
}

int main() {
    Book book1, book2;

    std::cout << "Enter the book title: ";
    std::cin >> book1.title;
    std::cout << "Enter the author's name: ";
    std::cin >> book1.author;
    std::cout << "Enter the book year: ";
    std::cin >> book1.year;
    std::cout << "Enter the book price: ";
    std::cin >> book1.price;

    std::cout << "Enter the book title: ";
    std::cin >> book2.title;
    std::cout << "Enter the author's name: ";
    std::cin >> book2.author;
    std::cout << "Enter the book year: ";
    std::cin >> book2.year;
    std::cout << "Enter the book price: ";
    std::cin >> book2.price;

    Book bookCollection[2] = {book1, book2};
    return 0;
}


// =============  RENDITION #3 ❌  =============
Book findCheapestBook(const Book& (bookCollection[2])) {  // Wrong parameters 
    if (bookCollection.empty()) {  // empty() method only for vector and strings
        Book emptyBook = {" ", " ", 0, 0};
        return emptyBook;
    } else {
        double cheapest = bookCollection[0].price;
        int index = 0;
        for (int i = 0; i < bookCollection.length(); i++) {
            if (bookCollection[i] > cheapest) {
                cheapest = bookCollection[i];  // Wrong type assignment
                index = i;
            }
        }
    }
    return index;  // Wrong return type
}

std::&ostream operator<<(const& ostream oss, const Book& bookCollection[cheapest]) {  // Wrong & placement, Wrong parameter
    oss << "Book title: " << book.title << "\n"
        << "Book author: " << book.author << "\n"
        << "Book year: " << book.year << "\n"
        << "Book price: " << book.price; 
    return oss;
}

int main() {
    Book book1, book2;
    std::cout << "Enter the book title: ";
    std::cin >> book1.title;
    std::cout << "Enter the author's name: ";
    std::cin >> book1.author;
    std::cout << "Enter the book year: ";
    std::cin >> book1.year;
    std::cout << "Enter the book price: ";
    std::cin >> book1.price;

    std::cout << "Enter the book title: ";
    std::cin >> book2.title;
    std::cout << "Enter the author's name: ";
    std::cin >> book2.author;
    std::cout << "Enter the book year: ";
    std::cin >> book2.year;
    std::cout << "Enter the book price: ";
    std::cin >> book2.price;

    Book bookCollection[2] = {book1, book2};
    int cheapest = findCheapestBook(bookCollection);  // Return type mismatch

    std::cout << bookCollection[cheapest] << std::endl;
    return 0;
}


// =============  RENDITION #4 ❌  =============
Book findCheapestBook (const Book (&bookList)[2]) {
    if (bookList.length() < 1) {  // Unnecessary when size is explicit
        Book emptyBook = {" ", " ", 0, 0};
        return emptyBook;
    } else {
        double cheapest = bookList[0].price;
        int index = 0;
        for (int i = 0; i < bookList.length(); i++) {  // C-style array do not have length() method
            if (bookList[i].price < cheapest) {
                cheapest = bookList[i].price;
                index = i;
            }
        }
        return bookList[index];
    }
}

std::ostream& operator<<(std::ostream& oss, const Book& cheapest) {
    oss << "Book title: " << cheapest.title << "\n"
        << "Book author: " << cheapest.author << "\n"
        << "Book year: " << cheapest.year << "\n"
        << "Book price: " << cheapest.price; 
    return oss;
}

int main() {
    Book book1, book2;
    std::cout << "Enter the book title: ";
    std::cin >> book1.title;
    std::cout << "Enter the author's name: ";
    std::cin >> book1.author;
    std::cout << "Enter the book year: ";
    std::cin >> book1.year;
    std::cout << "Enter the book price: ";
    std::cin >> book1.price;

    std::cout << "Enter the book title: ";
    std::cin >> book2.title;
    std::cout << "Enter the author's name: ";
    std::cin >> book2.author;
    std::cout << "Enter the book year: ";
    std::cin >> book2.year;
    std::cout << "Enter the book price: ";
    std::cin >> book2.price;

    Book bookList[2] = {book1, book2};
    Book cheapest = findCheapestBook(bookList);

    std::cout << cheapest << std::endl;
    return 0;
}


// =============  RENDITION #5 ✅  =============
Book findCheapestBook (const Book (&bookList)[2]) {
    double cheapest = bookList[0].price;
    int index = 0;
    for (int i = 0; i < 2; i++) {
        if (bookList[i].price < cheapest) {
            cheapest = bookList[i].price;
            index = i;
        }
    }
    return bookList[index];
}

std::ostream& operator<<(std::ostream& oss, const Book& cheapest) {
    oss << "Cheapest Book title: " << cheapest.title << "\n"
        << "Cheapest Book author: " << cheapest.author << "\n"
        << "Cheapest Book year: " << cheapest.year << "\n"
        << "Cheapest Book price: " << cheapest.price; 
    return oss;
}

int main() {
    Book book1, book2;
    std::cout << "Enter the book title: ";
    std::cin >> book1.title;
    std::cout << "Enter the author's name: ";
    std::cin >> book1.author;
    std::cout << "Enter the book year: ";
    std::cin >> book1.year;
    std::cout << "Enter the book price: ";
    std::cin >> book1.price;

    std::cout << "\n";

    std::cout << "Enter the book title: ";
    std::cin >> book2.title;
    std::cout << "Enter the author's name: ";
    std::cin >> book2.author;
    std::cout << "Enter the book year: ";
    std::cin >> book2.year;
    std::cout << "Enter the book price: ";
    std::cin >> book2.price;

    Book bookList[2] = {book1, book2};
    Book cheapest = findCheapestBook(bookList);

    std::cout << cheapest << std::endl;
    return 0;
}


