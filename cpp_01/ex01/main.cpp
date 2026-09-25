#include "Zombie.hpp"
#include <iostream>

int main(void) {
    int count = 6;
    int i = 0;
    Zombie* horde = zombieHorde(count, "myHorde");

    if (horde == NULL) {
        return 1;
    }

    while (i < count) {
        std::cout << "Zombie [" << i << "]: ";
        horde[i].announce();
        i++;
    }

    delete[] horde;
    return 0;
}