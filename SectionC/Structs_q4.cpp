// Question 1.4:  Nested Structures
/*
    Create a struct `Address` with fields for street, city, state, and zip code.
    Then, create a struct `Employee` that contains an `Address` struct, a name,
    and a salary.  Write a function that takes an `Employee` and prints a
    formatted employee record, including their full address.
*/

#include <iostream>
#include <string>
#include <sstream>

struct Address {
    std::string street;
    std::string city;
    std::string state;
    int zipcode;
};


// =============  RENDITION #1 ❌  =============
struct Employee : Address {  // Should use Composition over inheritance
    std::string name;
    int salary;
};

Employee createEmployee (
    std::string street,
    std::string city,
    std::string state,
    int zipcode,
    std::string name,
    int salary
) {
    Employee employee;
    employee.street = street;  // Should use address member
    employee.city = city;  // Should use address member
    employee.state = state;  // Should use address member
    employee.zipcode = zipcode;  // Should use address member
    employee.name = name;
    employee.salary = salary;

    return employee;
}

int main() {
    std::string street, city, state, name;
    int zipcode, salary;

    std::cout << "Enter street: ";
    std::cin >> street;  // Should use getline() instead
    std::cout << "Enter city: ";
    std::cin >> city;
    std::cout << "Enter state: ";
    std::cin >> state;
    std::cout << "Enter zipcode: ";
    std::cin >> zipcode;
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter salary: ";
    std::cin >> salary;

    Employee employee = createEmployee(street, city, state, zipcode, name, salary);
    std::cout << employee.name << std::endl;
}


// =============  RENDITION #2 ❌  =============
struct Employee {
    Address address;
    std::string name;
    int salary;
};

Employee createEmployee (
    std::string street,
    std::string city,
    std::string state,
    int zipcode,
    std::string name,
    int salary
) {
    Employee employee;
    employee.address.street = street;  
    employee.address.city = city; 
    employee.address.state = state;  
    employee.address.zipcode = zipcode;  
    employee.name = name;
    employee.salary = salary;

    return employee;
}

std::ostream& operator<<(std::ostream& oss, const Employee& employee) {
    oss << "Employee's street: " << employee.address.street << std::endl
        << "Employee's city: " << employee.address.city << std::endl
        << "Employee's state: " << employee.address.state << std::endl
        << "Employee's zipcode: " << employee.address.zipcode << std::endl
        << "Employee's name: " << employee.name << std::endl
        << "Employee's salary: " << employee.salary << std::endl;

    return oss;
}

int main() {
    std::string street, city, state, name;
    int zipcode, salary;

    std::cout << "Enter street: ";
    std::cin.ignore();
    std::getline(std::cin, street);

    std::cout << "Enter city: ";
    std::cin.ignore();  // Don't need cin.ignore()
    std::getline(std::cin, city);

    std::cout << "Enter state: ";
    std::cin.ignore();
    std::getline(std::cin, state);

    std::cout << "Enter zipcode: ";
    std::cin.ignore();  
    std::getline(std::cin, zipcode);  // Can't use getline for integer values

    std::cout << "Enter name: ";
    std::cin.ignore();  // Only needed here after using cin >>
    std::getline(std::cin, name);

    std::cout << "Enter salary: ";
    std::cin.ignore();
    std::getline(std::cin, salary);  // Can't use getline for integer values

    Employee employee = createEmployee(street, city, state, zipcode, name, salary);
    std::cout << employee << std::endl;
}


// =============  RENDITION #3 ✅  =============
struct Employee {
    Address address;
    std::string name;
    int salary;
};

Employee createEmployee (
    std::string street,
    std::string city,
    std::string state,
    int zipcode,
    std::string name,
    int salary
) {
    Employee employee;
    employee.address.street = street;  
    employee.address.city = city; 
    employee.address.state = state;  
    employee.address.zipcode = zipcode;  
    employee.name = name;
    employee.salary = salary;

    return employee;
}

std::ostream& operator<<(std::ostream& oss, const Employee& employee) {
    oss << "Employee's street: " << employee.address.street << std::endl
        << "Employee's city: " << employee.address.city << std::endl
        << "Employee's state: " << employee.address.state << std::endl
        << "Employee's zipcode: " << employee.address.zipcode << std::endl
        << "Employee's name: " << employee.name << std::endl
        << "Employee's salary: " << employee.salary << std::endl;

    return oss;
}

int main() {
    std::string street, city, state, name;
    int zipcode, salary;

    std::cout << "Enter street: ";
    std::cin.ignore();
    std::getline(std::cin, street);

    std::cout << "Enter city: ";
    std::getline(std::cin, city);

    std::cout << "Enter state: ";
    std::getline(std::cin, state);

    std::cout << "Enter zipcode: ";
    std::cin >> zipcode;

    std::cout << "Enter name: ";
    std::cin.ignore(); 
    std::getline(std::cin, name);

    std::cout << "Enter salary: ";
    std::cin >> salary;

    Employee employee = createEmployee(street, city, state, zipcode, name, salary);
    std::cout << employee << std::endl;
}
