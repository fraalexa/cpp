#include "Zombie.hpp"

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    if (N <= 0)
        return NULL;

    Zombie* horde_ptr = new Zombie[N];

    for (int i = 0; i < N; i++) {
        horde_ptr[i].setName(name);
    }

    return horde_ptr;
}