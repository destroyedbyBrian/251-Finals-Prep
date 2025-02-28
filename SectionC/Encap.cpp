// Question 4.1: Encapsulation (*.h and *.cpp)
/*
    Create a class `BankAccount` with private members `accountNumber` (string)
    and `balance` (double).  Provide public methods: `deposit`, `withdraw`,
    and `getBalance`.  Separate the class declaration (`BankAccount.h`) and
    implementation (`BankAccount.cpp`) into separate files.  Use header guards.
*/


// =============  RENDITION #1 ❌  =============
#include <iostream>
#include 'Encap.h'  // Should use angle brackets instead of single quotes

class BankAccount {  // Unnecessary to declare entire BankAccount class in .cpp file
private:
    std::string accountNumber;
    double balance;
public:
    BankAccount () : accountNumber(" "), balance(0) {}
    BankAccount (std::string acc, double b) : accountNumber(acc), balance(b) {}

    void deposit (double val) {}
    void withdraw (double val) {}
    double getBalance() {}  // header should be declared as const
};

void BankAccount::deposit (double val) {
    balance = balance + val;
}

void BankAccount::withdraw (double val) {
    balance = balance - val;
}

double BankAccount::getBalance () const { return balance; }


// =============  RENDITION #2 ❌  =============
#include "Encap.h"

BankAccount::BankAccount () : accountNumber(" "), balance(0) {}
BankAccount::BankAccount (std::string acc, double b) : accountNumber(acc), balance(b) {}
BankAccount::deposit (double val) {  // Missing return type
    balance = balance + val;
}
BankAccount::withdraw (double val) {  // Missing return type
    balance = balance - val;
}
BankAccount::getBalance () const { return balance; }  // Missing return type



// =============  RENDITION #3 ✅  =============
#include "Encap.h"

BankAccount::BankAccount () : accountNumber(" "), balance(0) {}
BankAccount::BankAccount (std::string acc, double b) : accountNumber(acc), balance(b) {}
void BankAccount::deposit (double val) {
    balance = balance + val;
}
void BankAccount::withdraw (double val) { 
    balance = balance - val;
}
double BankAccount::getBalance () const { return balance; }

