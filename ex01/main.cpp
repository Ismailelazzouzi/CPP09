#include "RPN.hpp"

int main(int ac, char **av)
{
    (void)av;
    if (ac != 2)
    {
        std::cerr << "Error: wrong argument number";
        return (1);
    }
    std::string str = *(++av);
    RPN myRPN;
    try
    {
        myRPN.parseString(str);
        myRPN.execute(str);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}