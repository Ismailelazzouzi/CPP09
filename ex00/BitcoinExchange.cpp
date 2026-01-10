#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange&)
{
    return *this;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange&){}

int poss(std::string str)
{
    int i = 0;
    while (isdigit(str[i]))
        i++;
    return i;
}

bool checkDate(std::string date)
{
    int arr[3];
    int i = 0;
    while (i < 3)
    {
        std::string placeholder = date;
        size_t pos = poss(date);
        if (pos == 0)
            break ;
        arr[i] = atoi(placeholder.substr(0, pos).c_str());
        date = date.substr(pos + 1);
        i++;
    }
    if (arr[0] < 2008 || !(arr[1] > 0 && arr[1] < 13) || !(arr[2] > 0 && arr[2] < 32))
        return false;
    return (true);
}

void BitcoinExchange::parseData()
{
    std::ifstream dataFile("data.csv");
    std::string line;
    while (getline(dataFile, line))
    {
        if (line == "date,exchange_rate")
            continue;
        size_t pos = line.find(",");
        if (pos == std::string::npos)
            break;
        std::string date = line.substr(0, pos);
        double value = stod(line.substr(pos + 1));
        dateValueData.insert({date, value});
    }
}

int BitcoinExchange::handleInput(std::string fileName)
{
    if (fileName != "input.csv")
    {
        std::cout << "wrong argument file name !" << std::endl;
        return (1);
    }
    std::ifstream inputFile(fileName);
    std::string line;
    while (getline(inputFile, line))
    {
        if (line == "date | value")
        continue;
    size_t pos = line.find("|");
    if (pos == std::string::npos)
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        continue;
    }
    std::string date = line.substr(0, pos);
    if (!checkDate(date))
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        continue;   
    }
    date = date.substr(0, 10);
    double value = stod(line.substr(pos + 2));
    if (value < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        continue;
    }
    else if (value > 1000)
    {
        std::cerr << "Error: too large a number. " << std::endl;
            continue;
    }
    std::map<std::string, double>::iterator iter = dateValueData.lower_bound(date);
    if (iter->first == date)
        std::cout << date << " => " << iter->second * value << std::endl;
    else if (iter->first != date && iter != dateValueData.begin())
    {
        iter--;
        std::cout << date << " => " << value << " = " << std::endl;
    }
    else
        std::cout << "this date is too early for the database" << std::endl;
    }
    return (0);
}
