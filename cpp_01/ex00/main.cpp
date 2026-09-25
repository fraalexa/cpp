#include "Zombie.hpp"

int main()
{
    Zombie  *zombie = newZombie("newtest");
    randomChump("test");
    zombie->announce();
    delete zombie;
    return (0);
}