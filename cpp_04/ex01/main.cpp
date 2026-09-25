#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main( void )
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;

    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

    const int count = 4;
    Animal* animals[count];

    for (int idx = 0; idx < count / 2; ++idx)
        animals[idx] = new Dog();

    for (int idx = count / 2; idx < count; ++idx)
        animals[idx] = new Cat();

    for (int idx = 0; idx < count; ++idx)
        animals[idx]->makeSound();

    for (int idx = 0; idx < count; ++idx)
        delete animals[idx];

    Dog originalDog;
    originalDog.getBrain()->setIdea(0, "Fetch the ball");

    Dog copyDog = originalDog;
    originalDog.getBrain()->setIdea(0, "Sleep on the couch");

    std::cout << "Original Dog Idea: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy Dog Idea: " << copyDog.getBrain()->getIdea(0) << std::endl;

    return 0;
}