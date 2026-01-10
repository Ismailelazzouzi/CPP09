#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <exception>

class RPN
{
    private:
        RPN &operator=(const RPN &){return *this;}
        RPN(const RPN &){}
        std::stack<int> rpncon;
    public:
        void    parseString(std::string &str);
        void    execute(std::string &str);
        RPN(){};
        ~RPN(){};
        class inputException : public std::exception
        {
            public :
            virtual const char* what() const throw();      
        };
};