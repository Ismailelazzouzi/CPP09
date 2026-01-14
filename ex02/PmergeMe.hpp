#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <exception>

class PmergeMe
{
private:
    std::vector<int> vcon;
    std::deque<int> dcon;
public:
    class inputException : public std::exception
    {
        public :
            virtual const char* what() const throw();   
    };
    void sortVcon();
    PmergeMe(std::string &);
    ~PmergeMe();
};
