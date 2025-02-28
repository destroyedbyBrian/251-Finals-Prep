// Question 4.4: Abstract Classes and Pure Virtual Functions
/*
    Create an abstract class `Animal` with a pure virtual function `makeSound()`. 
    Create derived classes like `Dog`, `Cat`, and `Cow` that inherit from `Animal` and implement `makeSound()` 
    to print their respective sounds. Demonstrate that you *cannot* create an instance of `Animal`, but you *can* 
    create instances of the derived classes and call `makeSound()` on them (using pointers to Animal is acceptable and encouraged).
*/

#include <iostream>

class Animal {
public:
    virtual void makeSound() = 0;
};

class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Woof" << std::endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Meow" << std::endl;
    }
};

class Cow : public Animal {
public:
    void makeSound() override {
        std::cout << "Moooo" << std::endl;
    }
};

int main () {
    Dog dog;
    Cat cat;
    Cow cow;
    
    Animal* animals[] = {&dog, &cat, &cow};

    for (int i = 0; i < 3; i++) {
        animals[i]->makeSound();
    }

    return 0;
}