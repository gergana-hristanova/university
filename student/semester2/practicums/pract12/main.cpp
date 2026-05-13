#include <iostream>
#include <cstring>

class Character;

class Spell
{
public:
    Spell() : name(nullptr) {}

    Spell(const char* name)
    : name(new char[strlen(name) + 1]{})
    {
        strcpy(this->name, name);
    }

    virtual Spell* clone() = 0;

    virtual ~Spell()
    {
        delete [] name;
    }

    virtual void cast() = 0;

    virtual void cast(Character* target) = 0;

protected:
    char* name;
};

class SpellBook
{
public:
    SpellBook()
    : size(0), capacity(0)
    {
        spells = new Spell*[capacity];
    }

    SpellBook& addSpell(Spell* spell)
    {
        if (size == capacity)
        {
            resize();
        }

        spells[size++] = spell;

        return *this;
    }

    void castSpell(int index)
    {
        spells[index]->cast();
    }

    void castSpell(int index, Character *target)
    {
        spells[index]->cast(target);
    }

    void castAll()
    {
        for (std::size_t i = 0; i < size; ++i)
        {
            spells[i]->cast();
        }
    }

    ~SpellBook()
    {
        for (std::size_t i = 0; i < size; ++i)
        {
            delete spells[i];
        }

        delete [] spells;
    }

private:
    Spell** spells;
    std::size_t size;
    std::size_t capacity;

    void resize()
    {
        if (capacity == 0)
        {
            capacity = 1;
        }

        Spell** newSpells = new Spell*[capacity *= 2];

        for (std::size_t i = 0; i < size; ++i)
        {
            newSpells[i] = spells[i];
        }

        delete [] spells;
        spells = newSpells;
    }
};

class Character
{
public:
    Character(const char* name, int health)
    : health(health),
      name()
    {
        strcpy(this->name, name);
    }

    Character& castSpell(int index)
    {
        spellBook.castSpell(index);

        return *this;
    }

    void takeDamage(int damage)
    {
        health = std::max(0, health - damage);
    }

    void heal(int points)
    {
        health += points;
    }

    void castSpell(int index, Character *target)
    {
        spellBook.castSpell(index, target);
    }

private:
    int health;
    char name[33];
    SpellBook spellBook;
};

class AttackSpell : public Spell
{
public:
    AttackSpell(const char* name)
     : Spell(name),
       size(0),
       capacity(0)
    {
        damageRolls = new int[capacity];
    }

    AttackSpell(const AttackSpell& other)
     : Spell(other.name),
       size(0),
       capacity(0)
    {
        damageRolls = new int[capacity];
    }

    void cast() override
    {
        std::cout << name << " deals damage rolls:" << std::endl;
        for (std::size_t i = 0; i < size; ++i)
        {
            std::cout << damageRolls[i] << std::endl;
        }
    }

    void cast(Character* target)
    {
        cast();
        for(std::size_t i = 0; i < size; ++i)
        {
            target->takeDamage(damageRolls[i]);
        }
    }

    Spell* clone() override
    {
        return new AttackSpell(*this);
    }

    AttackSpell& addDamageRoll(int damageRoll)
    {
        if (size == capacity)
        {
            resize();
        }

        damageRolls[size++] = damageRoll;

        return *this;
    }

    ~AttackSpell()
    {
        delete [] damageRolls;
    }

private:
    int* damageRolls;
    std::size_t size;
    std::size_t capacity;

    void resize()
    {
        if (capacity == 0)
        {
            capacity = 1;
        }

        int* newDmgRolls = new int[capacity *= 2];

        for (std::size_t i = 0; i < size; ++i)
        {
            newDmgRolls[i] = damageRolls[i];
        }

        delete [] damageRolls;
        damageRolls = newDmgRolls;
    }
};

class HealSpell : public Spell
{
public:
    HealSpell(const char* name)
     : Spell(name),
       size(0),
       capacity(0)
    {
        healRolls = new int[capacity];
    }

    HealSpell(const HealSpell& other)
     : Spell(other.name),
       size(0),
       capacity(0)
    {
        healRolls = new int[capacity];
    }

    Spell* clone() override
    {
        return new HealSpell(*this);
    }

    HealSpell& addDamageRoll(int damageRoll)
    {
        if (size == capacity)
        {
            resize();
        }

        healRolls[size++] = damageRoll;

        return *this;
    }

    void cast(Character* target)
    {
        cast();
        for(std::size_t i = 0; i < size; ++i)
        {
            target->heal(healRolls[i]);
        }
    }

    void cast() override
    {
        std::cout << name << " deals damage rolls:" << std::endl;
        for (std::size_t i = 0; i < size; ++i)
        {
            std::cout << healRolls[i] << std::endl;
        }
    }

    ~HealSpell()
    {
        delete [] healRolls;
    }

private:
    int* healRolls;
    std::size_t size;
    std::size_t capacity;

    void resize()
    {
        if (capacity == 0)
        {
            capacity = 1;
        }

        int* newHealRolls = new int[capacity *= 2];

        for (std::size_t i = 0; i < size; ++i)
        {
            newHealRolls[i] = healRolls[i];
        }

        delete [] healRolls;
        healRolls = newHealRolls;
    }
};

int main() {
    std::cout << "--- Creating Characters ---" << std::endl;
    Character mage = Character("Dumbledore", 100);
    Character dummy = Character("Dumbo", 10);

    std::cout << "--- Initializing Spells ---" << std::endl;
    AttackSpell* fireball = new AttackSpell("Fireball");
    fireball->addDamageRoll(10).addDamageRoll(15).addDamageRoll(20);

    HealSpell* lightHeal = new HealSpell("Light Heal");
    lightHeal->addDamageRoll(5).addDamageRoll(5); // Note: Your HealSpell uses addDamageRoll name

    std::cout << "--- Testing SpellBook ---" << std::endl;
    SpellBook myBook;
    myBook.addSpell(fireball);
    myBook.addSpell(lightHeal);

    std::cout << "\nTesting castAll():" << std::endl;
    myBook.castAll();

    std::cout << "\n--- Testing Clone (Deep Copy) ---" << std::endl;
    Spell* clonedFireball = fireball->clone();
    std::cout << "Cloned Spell Cast: ";
    clonedFireball->cast();

    std::cout << "\n--- Testing Targeted Casting ---" << std::endl;
    // This tests the interaction between Character and SpellBook
    myBook.castSpell(0, &dummy); // Cast Fireball on dummy
    myBook.castSpell(1, &mage);  // Cast Heal on mage

    std::cout << "\n--- Cleaning Up ---" << std::endl;
    // Manual cleanup for clones not in the book
    delete clonedFireball;

    std::cout << "Test completed successfully!" << std::endl;

    return 0;
}