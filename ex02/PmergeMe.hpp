#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <exception>
#include <sys/time.h>
#include <iomanip>

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
    int _size;
    void sortVcon();
    void sortDcon();
    void printVcon();
    void printDcon();
    PmergeMe(std::string &);
    ~PmergeMe();
};

int jnum(int);
bool comparePairs(const std::pair<int, int>& a, const std::pair<int, int>& b);

