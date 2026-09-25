#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main( void )
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    std::cout << "\ncheck Polymorphism" << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    std::cout << "\ndestructors" << std::endl;
    delete meta;
    delete j;
    delete i;

    std::cout << "\nwrong animal polymorphism test" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    wrongCat->makeSound();
    wrongMeta->makeSound();

    std::cout << "\nwrong destructors" << std::endl;
    delete wrongMeta;
    delete wrongCat;

    return 0;
}