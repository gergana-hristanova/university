#include <iostream>

class Agent
{
    public:
    Agent()
    {
        ++countAgents;
    }

    Agent(const Agent& other)
    {
        ++countAgents;
    }

    ~Agent()
    {
        --countAgents;
    }

    static unsigned getCount()
    {
        return countAgents;
    }

    private:
    static unsigned countAgents;
};

unsigned Agent::countAgents = 0;

int main()
{

    std::cout << Agent::getCount() << std::endl; // 0

    Agent smith, *jones;

    std::cout << Agent::getCount() << std::endl; // 1

    {
        Agent smith;
        jones = new Agent;
        std::cout << Agent::getCount() << std::endl; // 3
    }

    std::cout << Agent::getCount() << std::endl; // 2

    delete jones;

    std::cout << Agent::getCount() << std::endl; // 1

    return 0;
}