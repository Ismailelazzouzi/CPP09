#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <map>

class BitcoinExchange
{
    private :
        BitcoinExchange(const BitcoinExchange&);
        BitcoinExchange& operator=(const BitcoinExchange&);
        std::map <std::string, double> dateValueData;
        std::map <std::string, double> dateValue;
    public :
        BitcoinExchange();
        ~BitcoinExchange();
        void parseData();
        int handleInput(std::string fileName);
};