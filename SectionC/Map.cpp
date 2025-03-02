// Question 5.7. std::map
/*
    Create a std::map where the keys are strings (representing student names) and the values are integers (representing student IDs). 
    Add some entries, then write code to:
    - Check if a specific student name exists in the map.
    - Print all the key-value pairs in the map.
    - Find and print the ID associated with a given student name.
*/

#include <map>
#include <iostream>
#include <string>


// =============  RENDITION #1 ❌  =============
int main() {
    std::map<std::string, int> Students = {{"brian", 101}, {"bob", 102}};

    auto it = std::find(Students.begin(), Students.end(), "brian");

    if (it != Students.end()) {
        std::cout << "Found target at " << (it - Students.begin());
    }

    for (const auto& student : Students) {
        std::cout << student.first <<  ", " << student.second << std::endl; 
    }
    return 0;
}


// =============  RENDITION #2 ✅  =============
int main() {
    std::map<std::string, int> Students = {{"brian", 101}, {"bob", 102}};

    auto it = Students.find("brian");

    if (it != Students.end()) {
        std::cout << "Found target at " << it->first << ", " << it->second << std::endl;
    }

    for (const auto& student : Students) {
        std::cout << student.first <<  ", " << student.second << std::endl; 
    }
    return 0;
}
