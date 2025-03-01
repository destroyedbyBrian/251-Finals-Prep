// Question 5.1: Function Template
/*
    Write a function template `maximum` that takes two arguments of the same
    (but potentially different) type and returns the larger of the two.  The
    types should support the `>` operator. Test with int, double and std::string.
*/

#include <iostream>
#include <string>


// =============  RENDITION #1 ❌  =============
template<typename T>
maximum<T> (T t1, T t2) {  // Incorrect syntax
    if (t1 < t2) {  // ternary operator
        return t2;
    } else if (t1 > t2) {
        return t1;
    }
    // If arguments are equal
};  // Unnecessary semicolon

int main() {
    maximum<int>(2, 3);
    maximum<double>(2.3, 3.3);
    maximum<std::string>("h", "hhh");
    return 0;
}


// =============  RENDITION #2 ❌  =============
template <typename T>
T maximum (T t1, T t2) {
    if (t1 > t2) ? return t1 : return t2;  // Can't use if with ternary operator, can't use return within a ternary operator
}

int main() {
    int larger_int = maximum(2, 3);
    double larger_double = maximum(2.3, 3.3);
    std::string larger_string = maximum("hh", "hhh");

    std::cout << larger_int << ", " << larger_double << ", " << larger_string << std::endl; 
    return 0;
}


// =============  RENDITION #3 ✅  =============
template <typename T>
T maximum (T t1, T t2) {
    T result = (t1 > t2) ? t1 : t2;
    return result;
}

int main() {
    int larger_int = maximum<int>(2, 3);
    double larger_double = maximum<double>(2.3, 3.3);
    std::string larger_string = maximum<std::string>("hh", "hhhh");
    std::cout << larger_int << ", " << larger_double << ", " << larger_string << std::endl; 
return 0;
}