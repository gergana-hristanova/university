#include <iostream>
#include <functional>
#include <string>
#include <stdexcept>

using Command = std::function<void(const std::vector<std::string>&, std::ostream&)>;

void Echo(const std::vector<std::string>& args, std::ostream& os)
{
    for (std::string arg : args)
    {
        os << arg << " ";
    }

    os << std::endl;
}

void Add(const std::vector<std::string>& args, std::ostream& os)
{
    if (args.size() != 2)
    {
        throw std::invalid_argument("Number of arguments must be 2.");
    }

    double num1 = std::stod(args[0]);
    double num2 = std::stod(args[1]);

    os << num1 + num2 << std::endl;
}

void Mul(const std::vector<std::string>& args, std::ostream& os)
{
    if (args.size() != 2)
    {
        throw std::invalid_argument("Number of arguments must be 2.");
    }

    double num1 = std::stod(args[0]);
    double num2 = std::stod(args[1]);

    os << num1 * num2 << std::endl;
}

class CommandInterpreter
{
public:
    CommandInterpreter() : exit_executed(false)
    {
        // adds Exit command by default
        commands.push_back({ "Exit",
            [this](const std::vector<std::string>& args, std::ostream& os)->void
            {
                exit_executed = true;
                os << "Exiting...";
            }
        });

        // adds Help command by default
        commands.push_back({ "Help",
            [this](const std::vector<std::string>& args, std::ostream& os)->void
            {
                os << "Available commands:\n";
                for (std::pair<std::string, Command> pair : commands)
                {
                    os << "    " << pair.first << std::endl;
                }
            }
        });
    }

    void add_command(const std::string& name, Command &&command)
    {
        for (std::pair<std::string, Command> pair : commands)
        {
            if (pair.first == name)
            {
                throw std::invalid_argument("Command with such name already exists.");
            }
        }

        commands.push_back({ name, command });
    }

    void execute_command(const std::string& name, const std::vector<std::string>& args, std::ostream& out) const
    {
        for (std::pair<std::string, Command> pair : commands)
        {
            if (pair.first == name)
            {
                pair.second(args, out);
                return;
            }
        }

        throw std::invalid_argument("No command with such name exists.");
    }

    bool execute_command(std::istream& in, std::ostream& out) noexcept
    {
        try
        {
            std::string command_name;
            std::getline(in, command_name, ' ');

            std::vector<std::string> args;
            for (std::size_t i = 0; in.peek() != '\n'; ++i)
            {
                std::getline(in, args[i], ' ');
            }

            execute_command(command_name, args, out);

            return true;
        }
        catch(...)
        {
            return false;
        }
    }

    bool should_exit() const
    {
        return exit_executed;
    }

    void run(std::istream& in = std::cin, std::ostream& out = std::cout)
    {
        out << "Welcome to the command interpreter! Enter 'Help' for list of available commands.\n";
        
        while(!exit_executed)
        {
            execute_command(in, out);
        }
    }

private:
    std::vector<std::pair<std::string, Command>> commands;
    bool exit_executed;
};

int main()
{
    CommandInterpreter ci;
    ci.run();
}