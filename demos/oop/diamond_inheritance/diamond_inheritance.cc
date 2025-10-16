#include "diamond_inheritance.hpp"

Demos::DiamondInheritance::Person::Person() {
    std::cout << "This is Person()\n";
}

void Demos::DiamondInheritance::Person::speak() {
    std::cout << "Person::speak() is invoked\n";
}

Demos::DiamondInheritance::Mother::Mother(){
    std::cout << "This is Mother()\n";
}

Demos::DiamondInheritance::Father::Father(){
    std::cout << "This is Father()\n";
}

Demos::DiamondInheritance::Child::Child() {
    std::cout << "This is Child()\n";
}

void Demos::DiamondInheritance::Run(void)
{
    std::cout << "# Diamond inheritance resolution\n";
    Demos::DiamondInheritance::Child chill_dude;
    chill_dude.speak();
}