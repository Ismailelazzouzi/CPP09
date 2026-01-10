#include "RPN.hpp"

bool isoperator(char c)
{
    if (c == '+' || c == '-' || c == '/' || c == '*')
        return true;
    return false;
}

void    RPN::parseString(std::string &str)
{
    if (isdigit(str[str.length() - 1]))
        throw inputException();
    for (int i = 0; i < (int)str.length(); i++)
    {
        if (!isdigit(str[i]) && !isspace(str[i]) && !isoperator(str[i]))
            throw inputException();
    }
}

void    RPN::execute(std::string &str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (isspace(str[i]))
            continue;
        else if (isdigit(str[i]))
        {
            if (isdigit(str[i + 1]) || isdigit(str[i - 1]))
                throw inputException();
            rpncon.push(str[i] - '0');
            continue;
        }
        else
        {
            if (rpncon.size() < 2)
                throw inputException();
            int num1, num2, res;
            num1 = rpncon.top();
            rpncon.pop();
            num2 = rpncon.top();
            switch (str[i])
            {
                case '+' : res = num1 + num2;
                    break;
                case '-' : res = num2 - num1;
                    break;
                case '*' : res = num2 * num1;
                    break;
                case '/' : res = (num1 != 0) ? (num2 / num1) : throw inputException();
                    break;
            }
            rpncon.pop();
            rpncon.push(res);
        }
    }
    if (rpncon.size() != 1)
        throw inputException();
    std::cout << rpncon.top() << std::endl;
}

const char *RPN::inputException::what() const throw()
{
    return "FUCKED UP INPUT";
}