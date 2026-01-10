#pragma once

#include <iostream>
#include <string>
#include <stack>

class RPN
{
    private:
        RPN &operator=(const RPN &){return *this;}
        RPN(const RPN &){}
        std::stack<char> RPNcon;
    public:
        RPN(){};
        ~RPN(){};
};