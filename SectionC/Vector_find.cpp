// Question 5.4: Generic Algorithm (std::find)
/*
    Write a function that takes a `std::vector<std::string>` and a target
    string as input. Use `std::find` to search for the target string within
    the vector.  If the string is found, print its index; otherwise, print
    a "not found" message.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


// =============  RENDITION #1 ❌  =============
std::string findString(std::vector<std::string>& stringList, std::string& target) {
    std::string p = std::find(stringList, target);  // std::find requires 3 parameters: beginning&end iterator + value to find
    return p;  // Returns an iterator not string
}

int main() {
    std::string t;
    std::cout << "Enter target string: ";
    std::cin.ignore();
    std::getline(std::cin, t);
    
    std::vector<std::string> stringList;  // Not populated with any values
    findString(stringList, t);
    return 0;
}


// =============  RENDITION #2 ❌  =============
void findString (std::vector<std::string>& stringList, std::string& target) {
    auto it = std::find(stringList.begin(), stringList.end(), target);

    if (it != stringList.end()) {
        std::cout << "Found at Index: " << *it;  // Should find index position by finding dist between 2 iterators
    } else {
        std::cout << "not found";
    }
}

int main() {
    std::string t;
    std::cout << "Enter target string: ";
    std::cin.ignore();  // Unnecessary, use only when switching from e.g. int input to getline()
    std::getline(std::cin, t);
    
    std::vector<std::string> stringList = {"hello", "world", "ni", "hao"}; 
    findString(stringList, t);
    return 0;
}


// =============  RENDITION #3 ✅  =============
void findString (std::vector<std::string>& stringList, std::string& target) {
    auto it = std::find(stringList.begin(), stringList.end(), target);

    if (it != stringList.end()) {
        std::cout << "Found at Index: " << it - stringList.begin();  
    } else {
        std::cout << "not found";
    }
}

int main() {
    std::string t;
    std::cout << "Enter target string: ";
    std::getline(std::cin, t);
    
    std::vector<std::string> stringList = {"hello", "world", "ni", "hao"}; 
    findString(stringList, t);
    return 0;
}