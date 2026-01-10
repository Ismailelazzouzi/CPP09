#include "RPN.hpp"

int main(int ac, char **av)
{
    (void)av;
    if (ac != 2)
    {
        std::cerr << "Error: wrong argument number" << std::endl;
        return (1);
    }
    
    std::cout << "SUCCESS" << std::endl;
    return (0);
}