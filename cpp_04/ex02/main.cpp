#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const int count = 4;
    const Animal* animals[count];

    for (int i = 0; i < count / 2; i++)
        animals[i] = new Dog();
    for (int i = count / 2; i < count; i++)
        animals[i] = new Cat();

    for (int i = 0; i < count; i++) {
        std::cout << animals[i]->getType() << ": ";
        animals[i]->makeSound();
    }

    for (int i = 0; i < count; i++)
        delete animals[i];

    Dog original;
    original.getBrain()->setIdea(0, "Original Idea");

    Dog copy(original);
    copy.getBrain()->setIdea(0, "Modified Idea");

    std::cout << "Original Idea 0: " << original.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy Idea 0:     " << copy.getBrain()->getIdea(0) << std::endl;

    return 0;
}