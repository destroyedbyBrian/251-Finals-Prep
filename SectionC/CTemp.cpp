// Question 5.2: Class Template
/*
    Create a class template `Pair` that can hold two values of potentially
    different types. Provide member functions `getFirst()` and `getSecond()`
    to access the values.
*/

#include <iostream>
#include <string>

template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;
public:
    Pair () : first(0), second(0) {}
    Pair (T1 t1, T2 t2) : first(t1), second(t2) {}
    T1 getFirst() const { return first; }
    T2 getSecond() const { return second; }
};

int main() {
    Pair<int, double> pair1(3, 5.5);
    
    std::cout << pair1.getFirst() << ", " << pair1.getSecond() << std::endl;

    return 0;
}