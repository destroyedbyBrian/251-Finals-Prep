
// Question 5.6: Using std::sort with a Custom Comparator
/*
    Create a vector of `Book` objects (from Question 1.1).  Use `std::sort` to sort the vector in *descending* order of book price.  
    You'll need to define a custom comparator (either a function object or a lambda expression) for this.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

struct Book {
    std::string title;
    std::string author;
    int year;
    double price;
};


// =============  RENDITION #1 ❌  =============
void sortInDescendingPrice(std::vector<Book>& bookList) {
    auto it = std::sort (bookList.begin(), bookList.end(), bookList[0].price);  // Needs comparator function or lambda expression to compare two book objects
    std::cout << *it << std::endl;
}

int main() {
    Book book1 = {"thomas", "god", 0, 19.99};
    Book book2 = {"luke", "god", 0, 9.99};
    Book book3 = {"matthew", "god", 0, 9.99};
    std::vector<Book>bookList = {book1, book2, book3};

    sortInDescendingPrice(bookList);
    return 0;
}


// =============  RENDITION #2 ✅  =============
void sortInDescendingPrice(std::vector<Book>& bookList) {
    std::sort (
        bookList.begin(), 
        bookList.end(),
        [](const Book& a, const Book& b) {
            return a.price > b.price;
        }
    );  
}

void printBooks(const std::vector<Book>& bookList) {
    for(const auto& book : bookList) {
        std::cout << book.title << ": $" << book.price << std::endl;
    }
}

int main() {
    Book book1 = {"thomas", "god", 0, 19.99};
    Book book2 = {"luke", "god", 0, 0.99};
    Book book3 = {"matthew", "god", 0, 9.99};
    std::vector<Book>bookList = {book1, book2, book3};

    sortInDescendingPrice(bookList);
    printBooks(bookList);
    return 0;
}