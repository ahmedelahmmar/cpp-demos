#pragma once

#include <iostream> 

namespace Demos::DiamondInheritance
{

class Person {
public:
    Person();
    void speak(void);
};

// virtual inheritance resolves the problem
class Mother : virtual public Person {
public:
    Mother();
};

class Father : virtual public Person {
public:
    Father();
};

class Child : public Mother, public Father {
public:
    Child();
};

void Run(void);

} // namespace Inheritance
