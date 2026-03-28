#include <iostream>
#include <cstring>
#include <cmath>

constexpr std::size_t EPSILON = 1e-9;

class Dish
{
public:
    Dish(char* name = "", float price = 0.0, unsigned quantity = 0, unsigned calories = 0)
    : name(new char[strlen(name) + 1]{}),
      price(price),
      quantity(quantity),
      calories(calories)
    {
        strcpy(this->name, name);
    }
    
    friend std::istream& operator>>(std::istream& is, Dish& dish)
    {
        char name[dish.NAME_MAX_SIZE + 1];
        float price;
        unsigned quantity, calories;

        is.getline(dish.name, dish.NAME_MAX_SIZE);
        is >> price >> quantity >> calories;
        is.ignore();

        dish = Dish(name, price, quantity, calories);

        return is;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Dish& dish)
    {
        os << dish.name << std::endl
           << dish.price << std::endl
           << dish.quantity << std::endl
           << dish.calories << std::endl;
        
        return os;
    }

    bool operator<(const Dish& other) const
    {
        if (fabs(priceToQuantity() - other.priceToQuantity()) < EPSILON)
        {
            return priceToQuantity() < other.priceToQuantity();
        }

        return calories < other.calories;
    }

private:
    char* name;
    float price;
    unsigned quantity, calories;
    static constexpr std::size_t NAME_MAX_SIZE = 256;

    float priceToQuantity() const
    {
        return price / quantity;
    }
};

class Menu
{
    
};

int main()
{

}