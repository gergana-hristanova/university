#include <iostream>

enum class AttackType
{
    PHYSICAL,
    FIRE,
    WATER,
    LIGHTNINg,
    HOLY,
};

class Character
{
public:
    void takeDamage(int power, AttackType type)
    {
        health = std::max(0, health - power);
    }

    bool isAlive()
    {
        return health == 0;
    }

private:
    int health;
};

int main()
{

}