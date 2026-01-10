#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac != 2)
        {
            std::cout << "wrong argument number !" << std::endl;
            return (1);
        }
        std::string fileName = std::string(*(++av));
        BitcoinExchange btc;
        btc.parseData();
        if (btc.handleInput(fileName) == 1)
            return (1);
        std::cout << "SUCCESS!" << std::endl;
    }
    catch (const std::ios_base::failure& e)
    {
        std::cerr << "Exception : " << e.what() << std::endl;
    }
    return (0);
}