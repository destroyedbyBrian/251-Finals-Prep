// Question 3.4:  Overloading += for a StringList class
/*
    Create a basic class StringList that manages a dynamically allocated array of strings.  
    Overload the += operator to append a new string to the list.  
    Ensure proper memory management (allocate more space when needed, avoid memory leaks).  Include a destructor.
*/


// =============  RENDITION #1 ❌  =============
#include <iostream>
#include <vector>
#include <string>

class StringList {
public:
    std::vector<std::string> msgList;  // Should use manual memory management instead

    StringList operator+=(const std::string& msg) {
        msgList.push_back(msg);
        // Missing return statement
    }

    // Missing Destructor
};

int main() {
    StringList list1;
    list1 += "Hello world";
    for (const auto& msg : list1.msgList) {
        std::cout << msg << std::endl;
    }
    return 0;
}


// =============  RENDITION #2 ✅  =============
#include <iostream>
#include <string>
#include <cstring>

class StringList {
private:
    std::string* strings;
    size_t size;     // total capacity of the array
    size_t capacity; // number of elements currently stored

public:
    StringList() : strings(new std::string[1]), size(1), capacity(0) {}  // Allocate memory for an array of 1

    ~StringList() {
        delete[] strings;
    }

    StringList& operator+=(const std::string& msg) {
        if (capacity >= size) {
            // Double the size
            size_t newSize = size * 2;
            std::string* newStrings = new std::string[newSize];
            
            // Copy existing strings
            for (size_t i = 0; i < capacity; i++) {
                newStrings[i] = strings[i];
            }
            
            // Delete old array and update pointers
            delete[] strings;
            strings = newStrings;
            size = newSize;
        }
        
        // Add the new string at the current capacity position, then increment capacity
        strings[capacity] = msg;
        capacity++;
        return *this;
    }

    // Getter methods
    size_t getSize() const { return capacity; }
    const std::string& getString(size_t index) const { return strings[index]; }
};

int main() {
    StringList list1;
    list1 += "Hello";
    list1 += "world";
    
    for (size_t i = 0; i < list1.getSize(); i++) {
        std::cout << list1.getString(i) << std::endl;
    }
    return 0;
}
