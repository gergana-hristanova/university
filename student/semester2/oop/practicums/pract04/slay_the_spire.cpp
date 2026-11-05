#include <iostream>
#include <cstring>
#include <functional>

enum class CardType
{
    Additive,
    Multiplic
};

enum class CharacterType
{
    Aggressive,
    Passive,
    Merchant,
    Player
};

using Modifier = std::function<int(int)>;

class Character
{
    public:
    Character(char* name, CharacterType type, int health, int armor, Card* cards, Modifier* modifiers, std::size_t mods_size)
    : type(type),
      health(health),
      armor(armor),
      mods_size(mods_size)
    {
        stpcpy(this->name, name);
        for(std::size_t i = 0; i < cards_size; ++i)
        {
            this->cards[i] = cards[i];
        }
        for(std::size_t i = 0; i < mods_size; ++i)
        {
            this->modifiers[i] = modifiers[i];
        }
    }

    void add_armor(int armor)
    {
        this->armor += armor;
    }

    void damageHealth(int damage)
    {
        health -= damage;
        if (health < 0)
        {
            health = 0;
        }

        std::cout << "Character " << this->name << " has died!";
    }

    void damage_armor(int damage)
    {
        this->armor -= damage;
        if (armor < 0)
        {
            damageHealth(abs(this->armor));
            armor = 0;
        }
    }

    Modifier* get_mods()
    {
        return this->modifiers;
    }

    std::size_t get_mods_size() const
    {
        return this->mods_size;
    }

    private:
    static const std::size_t MAX_CARDS = 16;
    char* name;
    CharacterType type;
    int health;
    int armor;
    Card* cards;
    Modifier modifiers[4];
    size_t mods_size;
    std::size_t cards_size;
};

class Card
{
    public:
    Card(CardType type, int damage, int armor)
    : type(type),
      damage(damage),
      armor(armor)
    {
        if (type == CardType::Additive)
        {
            value.points = DEFAULT_POINTS;
        }
        else
        {
            value.mult = DEFAULT_MULT;
        }
    }

    void play(Character& ch1, Character& ch2)
    {
        ch1.add_armor(this->armor);
        damage_to(ch2);
    }

    private:
    void damage_to(Character ch)
    {
        int deal_dmg = 0;
        if (type == CardType::Additive)
        {
            deal_dmg = this->damage + this->value.points;
        }
        else
        {
            deal_dmg = this->damage * this->value.mult;
        }

        std::size_t ch_mods_size = ch.get_mods_size();
        Modifier* ch_mods = ch.get_mods();
        for(std::size_t i = 0; i < ch_mods_size; ++i)
        {
            deal_dmg = ch_mods[i](deal_dmg);
        }

        ch.damage_armor(deal_dmg);
    }

    const static int DEFAULT_POINTS = 5;
    const static float DEFAULT_MULT = 1.5;
    CardType type;
    union
    {
        int points;
        float mult;
    } value;
    
    int damage;
    int armor;
};

class Card
{
    public:
    Card(CardType type, int damage, int armor)
    : type(type),
      damage(damage),
      armor(armor)
    {
        if (type == CardType::Additive)
        {
            value.points = DEFAULT_POINTS;
        }
        else
        {
            value.mult = DEFAULT_MULT;
        }
    }

    void play(Character& ch1, Character& ch2)
    {
        ch1.add_armor(this->armor);
        damage_to(ch2);
    }

    private:
    void damage_to(Character ch)
    {
        int deal_dmg = 0;
        if (type == CardType::Additive)
        {
            deal_dmg = this->damage + this->value.points;
        }
        else
        {
            deal_dmg = this->damage * this->value.mult;
        }

        std::size_t ch_mods_size = ch.get_mods_size();
        Modifier* ch_mods = ch.get_mods();
        for(std::size_t i = 0; i < ch_mods_size; ++i)
        {
            deal_dmg = ch_mods[i](deal_dmg);
        }

        ch.damage_armor(deal_dmg);
    }

    const static int DEFAULT_POINTS = 5;
    const static float DEFAULT_MULT = 1.5;
    CardType type;
    union
    {
        int points;
        float mult;
    } value;
    
    int damage;
    int armor;
};