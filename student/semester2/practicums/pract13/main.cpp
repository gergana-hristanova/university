#include <iostream>
#include <string>
#include <vector>

class Building
{
public:
    Building() : happiness(0), name("") {}

    Building(std::string name, float happiness)
    : happiness(happiness), name(name)
    {}

    virtual float trigger_effect(float current_happiness) const = 0;

    virtual Building* copy() const = 0;

    virtual ~Building() {}

    float happiness;
    std::string name;
};

class Park : public Building
{
    public:

    Park() : Building("Park", 10) {}

    Park* copy() const final
    {
        return new Park(*this);
    }

    float trigger_effect(float current_happiness) const final
    {
        return current_happiness * 1.10;
    }
};

class School : public Building
{
    public:

    School() : Building("School", 20) {}

    School* copy() const final
    {
        return new School(*this);
    }

    float trigger_effect(float current_happiness) const final
    {
        return current_happiness * 1.10;
    }
};

class Hospital : public Building
{
    public:

    Hospital() : Building("Hospital", 30) {}

    Hospital* copy() const final
    {
        return new Hospital(*this);
    }

    float trigger_effect(float current_happiness) const final
    {
        return current_happiness;
    }
};

class BusinessPark : public Building
{
    public:

    BusinessPark() : Building("Hospital", 30) {}

    BusinessPark* copy() const final
    {
        return new BusinessPark(*this);
    }

    float trigger_effect(float current_happiness) const final
    {
        return current_happiness * 1.25;
    }
};

class Mayor
{
public:
    Mayor(std::string name, float happiness_modifier)
    : happiness_modifier(happiness_modifier), name(name)
    {}

    virtual Mayor* copy() const = 0;

    virtual float influence(Building** buildings, int num_buildings) const
    {
        float current_happiness = 0;

        for (int i = 0; i < num_buildings; ++i)
        {
            current_happiness += buildings[i]->happiness;
        }

        for (int i = 0; i < num_buildings; ++i)
        {
            current_happiness = buildings[i]->trigger_effect(current_happiness);
        }

        current_happiness += happiness_modifier;

        return current_happiness;
    }

    virtual ~Mayor() {}

    float happiness_modifier;

private:
    std::string name;
};

class Mamdani : public Mayor
{
public:
    Mamdani() : Mayor("Mamdani", 5)
    {}

    Mamdani* copy() const
    {
        return new Mamdani();
    }

    float influence(Building** buildings, int num_buildings) const final
    {
        float current_happiness = 0;

        for (int i = 0; i < num_buildings; ++i)
        {
            current_happiness += buildings[i]->happiness;
        }

        for (int i = 0; i < num_buildings; ++i)
        {
            current_happiness = buildings[i]->trigger_effect(current_happiness);

            buildings[i]->happiness *= 1.25; //special Mamdani ability
        }

        current_happiness += happiness_modifier;

        return current_happiness;
    }
};

class Terziev : public Mayor
{
public:
    Terziev() : Mayor("Terziev", 5)
    {}

    Terziev* copy() const
    {
        return new Terziev;
    }

    float influence(Building** buildings, int num_buildings) const final
    {
        float current_happiness = 0;

        for (int i = 0; i < num_buildings; ++i)
        {
            current_happiness += buildings[i]->happiness;
        }

        for (int i = 0; i < num_buildings; ++i)
        {
            current_happiness = buildings[i]->trigger_effect(current_happiness);

            // special Terziev ability
            current_happiness = buildings[i]->trigger_effect(current_happiness);
        }

        current_happiness += happiness_modifier;

        return current_happiness;
    }
};

class GhettoMan : public Mayor
{
public:
    GhettoMan() : Mayor("Ghetto Man", -10)
    {}

    GhettoMan* copy() const
    {
        return new GhettoMan();
    }

    float influence(Building** buildings, int num_buildings) const final
    {
        float current_happiness = 0;

        for (int i = 0; i < num_buildings; ++i)
        {
            current_happiness += buildings[i]->happiness;
        }

        for (int i = 0; i < num_buildings; ++i)
        {
            current_happiness = buildings[i]->trigger_effect(current_happiness);

            buildings[i]->happiness *= 0.80; //special GhettoMan ability
        }

        current_happiness += happiness_modifier;

        return current_happiness;
    }
};

class Municipality : public Building
{
public:
    Municipality(const Mayor& mayor)
    : mayor(mayor.copy())
    {}

    Municipality(const Municipality& other)
     : Building(other.name, other.happiness),
       mayor(other.mayor->copy())
    {
        for (const Building* b : other.buildings)
        {
            buildings.push_back(b->copy());
        }
    }

    Municipality* copy() const override
    {
        return new Municipality(*this);
    }

    float calculate_happiness()
    {
        return mayor->influence(buildings.data(), buildings.size());
    }

    void add_building(const Building &building)
    {
        buildings.push_back(building.copy());
    }

    float trigger_effect(float current_happiness) const final
    {
        return current_happiness + mayor->happiness_modifier;
    }

    ~Municipality()
    {
        for (Building* b : buildings)
        {
            delete b;
        }

        delete mayor;
    }

    Mayor* mayor;
    std::vector<Building*> buildings;
};

class City
{
public:
    void add_municipality(const Municipality& municipality)
    {
        municipalities.push_back(municipality.copy());
    }

    float calculate_total_happiness()
    {
        float total_happiness = 0;

        for (Municipality* m : municipalities)
        {
            total_happiness += m->calculate_happiness();
            total_happiness += m->mayor->influence(m->buildings.data(), m->buildings.size());
        }

        return total_happiness;
    }

    ~City()
    {
        for (Municipality* m : municipalities)
        {
            delete m;
        }
    }

private:
    std::string name;
    std::vector<Municipality*> municipalities;
};

int main()
{
    City sofia;

    Municipality yavorov = Municipality(Mamdani());
    yavorov.add_building(Park());
    yavorov.add_building(BusinessPark());
    
    Municipality lyulin = Municipality(GhettoMan());
    lyulin.add_building(School());
    lyulin.add_building(Hospital());

    sofia.add_municipality(yavorov);
    sofia.add_municipality(lyulin);

    std::cout << sofia.calculate_total_happiness();
}