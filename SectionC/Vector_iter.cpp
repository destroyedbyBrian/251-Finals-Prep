// Question 5.3: STL Vector and Iterators
/*
    Write a function that takes a `std::vector<int>` as input and uses iterators
    (both forward and reverse) to print the elements of the vector, first
    in the original order and then in reverse order.
*/

#include <iostream>
#include <vector>


// =============  RENDITION #1 ❌  =============
void runThrough (std::vector<int>& vectorList) {
    for (std::vector<int>::const_iterator cit = vectorList.begin(); cit < vectorList.end(); cit++) {  // Better to use != over <
        std::cout << *cit << std::endl;
    }

    for (std::vector<int>::const_iterator cit = vectorList.begin(); cit < vectorList.end(); cit--) {  // Reverse with .rbegin()
        std::cout << *cit.reverse() << std::endl;  // no .reverse() method for iterators
    }
}

int main() {
    std::vector<int> vectorList = {1, 2, 3, 4, 5};
    runThrough(vectorList);
    return 0;
}


// =============  RENDITION #2 ✅  =============
void runThrough (std::vector<int>& vectorList) {
    for (std::vector<int>::const_iterator cit = vectorList.begin(); cit != vectorList.end(); ++cit) {  
        std::cout << *cit << std::endl;
    }

    for (std::vector<int>::const_reverse_iterator crit = vectorList.rbegin(); crit != vectorList.rend(); ++crit) { 
        std::cout << *crit << std::endl;  
    }
}

int main() {
    std::vector<int> vectorList = {1, 2, 3, 4, 5};
    runThrough(vectorList);
    return 0;
}