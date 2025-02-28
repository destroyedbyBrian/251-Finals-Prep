// Question 4.1: Encapsulation (*.h and *.cpp)
/*
    Create a class `BankAccount` with private members `accountNumber` (string)
    and `balance` (double).  Provide public methods: `deposit`, `withdraw`,
    and `getBalance`.  Separate the class declaration (`BankAccount.h`) and
    implementation (`BankAccount.cpp`) into separate files.  Use header guards.
*/


// // =============  RENDITION #1 ❌  =============
// #ifndef BANKACCOUNT_H
// #define BANKACCOUNT_H

// #include <string>

// class BankAccount {
// private:
//     std::string accountNumber;
//     double balance;
// public:
//     BankAccount () : accountNumber(" "), balance(0) {}  // Should have nth after the bracket 
//     BankAccount (std::string acc, double b) : accountNumber(acc), balance(b) {}

//     void deposit (double val) {}  // Empty bodies {} should be removed
//     void withdraw (double val) {}  // Empty bodies {} should be removed
//     double getBalance() {}  // Empty bodies {} should be removed
// };

// #endif


// // =============  RENDITION #2 ❌  =============
// #ifndef BANKACCOUNT_H
// #define BANKACCOUNT_H

// #include <string>

// class BankAccount {
// private:
//     std::string accountNumber;
//     double balance;
// public:
//     BankAccount()  // Missing ;
//     BankAccount(std::string acc, double b)  // Missing ;
//     void deposit (double val)  // Missing ;
//     void withdraw (double val)  // Missing ;
//     double getBalance ()  // Missing ;, const
// };

// #endif


// =============  RENDITION #3 ✅  =============
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>

class BankAccount {
private:
    std::string accountNumber;
    double balance;
public:
    BankAccount();
    BankAccount(std::string acc, double b);
    void deposit (double val);
    void withdraw (double val);
    double getBalance () const;
};

#endif