// Question 1.3: Struct with Pointers and Dynamic Allocation
/*
    Define a struct `Student` with members: `name` (string), `id` (int), and
    `grades` (a pointer to an array of doubles).  Write a function `createStudent`
    that takes a name, ID, and the number of grades as input.  This function
    should dynamically allocate the `grades` array, prompt the user to enter
    each grade, store the grades in the array, and return a `Student` struct.
    Also, write a `deleteStudent` function that releases the dynamic memory of the grade array.
*/

#include <iostream>
#include <string>


// =============  RENDITION #1 ❌  =============
struct Student {
    std::string name;
    int id;
    double* gradeSize;  // gradSzie should be an integer
};

Student createStudent (const std::string& name, const int& id, const double& gradeSize) {
    double gradeList[gradeSize] = {};  // Use new[] for dynamic allocation
    for (int i = 0; i < gradeSize; i++) {
        std::cout << "Enter grade: ";
        std::cin >> gradeList;  // Should Read into element in array individually instead
    }
    return &gradeList[];  // Should return Student object not address
}

void deleteStudent(Student& student1) {
    delete double* student1.gradeSize[];  // Wrong syntax
}

int main() {
    Student student1;
    std::cout << "Enter Student's name: ";
    std::cin >> student1.name;
    std::cout << "Enter Student's ID: ";
    std::cin >> student1.id;
    std::cout << "Enter number of grades: ";
    std::cin >> student1.gradeSize;  // Storing to pointer which is incorrect

    createStudent(student1);  // Passing the wrong arguments to function
    deleteStudent(student1);

    return 0;
}


// =============  RENDITION #2 ❌  =============
struct Student {
    std::string name;
    int id;
    int numOfGrades;
    double* grades;
};

Student createStudent(Student& student) {  // Wrong approach
    student.grades = new [];  // Must specifiy the type and number of elements
    for (int i = 0 ; i < student.numOfGrades; i++) {
        std::cout << "Enter grade: ";
        std::cin >> student.grades.append()  // Pointer does not have append() method
    }
    std::cout << "Dynamic memory created" << std::endl;
    return student;  // Causes shallow copy, when I return new Student by value w/o custom copy constructor
}

void deleteStudent(Student& student) {
    delete[] student.grades;
    std::cout << "Dynamic memory cleared" << std::endl;
}

int main() {
    Student student1;
    std::cout << "Enter Student's name: ";
    std::cin >> student1.name;
    std::cout << "Enter Student's ID: ";
    std::cin >> student1.id;
    std::cout << "Enter number of grades: ";
    std::cin >> student1.numOfGrades;  

    createStudent(student1);  // Use the return value
    deleteStudent(student1);

    return 0;
}


// =============  RENDITION #3 ✅  =============
struct Student {
    std::string name;
    int id;
    int numOfGrades;
    double* grades;
};

Student createStudent(std::string& name, int& id, int& numOfGrades) { 
    Student student;
    student.name = name;
    student.id = id;
    student.numOfGrades = numOfGrades;
    student.grades = new double[numOfGrades];  

    for (int i = 0 ; i < student.numOfGrades; i++) {
        std::cout << "Enter grade: ";
        std::cin >> student.grades[i];  
    }
    std::cout << "Dynamic memory created" << std::endl;
    return student;  
}

void deleteStudent(Student& student) {
    delete[] student.grades;
    student.grades = nullptr;
    std::cout << "Dynamic memory cleared" << std::endl;
}

int main() {
    std::string name;
    int id, numOfGrades;
    
    std::cout << "Enter Student's name: ";
    std::cin >> name;
    std::cout << "Enter Student's ID: ";
    std::cin >> id;
    std::cout << "Enter number of grades: ";
    std::cin >> numOfGrades;  

    Student student1 = createStudent(name, id, numOfGrades);  // Use the return value
    deleteStudent(student1);

    return 0;
}


// =============  RENDITION #4: Prevent Shallow Copying ✅  =============
struct Student {
    std::string name;
    int id;
    int numOfGrades;
    double* grades;

    // Default Constructor
    Student() : name(""), id(0), numOfGrades(0), grades(nullptr) {}

    // Constructor
    Student(std::string n, int i, int nG) : name(n), id(i), numOfGrades(nG) {
        grades = new double[numOfGrades];
    }

    // Copy Constructor
    Student (const Student& other) : name(other.name), id(other.id), numOfGrades(other.numOfGrades) {
        grades = new double[numOfGrades];
        for (int i = 0; i < numOfGrades; i++) {
            grades[i] = other.grades[i];
        }
    }

    // Assignment Operater
    Student& operator=(const Student& other) {
        if (this != &other) {
            delete[] grades;
        
            name = other.name;
            id = other.id;
            numOfGrades = other.numOfGrades;
            grades = new double[numOfGrades];
            for (int i = 0; i < numOfGrades; i++) {
                grades[i] = other.grades[i];
            }
        }
        return *this;
    }

    // Destructor
    ~Student() {
        delete[] grades;
        grades = nullptr;
    }
};
