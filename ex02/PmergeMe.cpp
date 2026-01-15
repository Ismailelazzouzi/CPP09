#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::string &input)
{
    std::istringstream splitted(input);
    std::string n;
    while (splitted >> n)
    {
        for (size_t i = 0; i < n.size(); i++)
        {
            if (!isdigit(n[i]))
                throw PmergeMe::inputException();
        }
        int number = atoi(n.c_str());
        if (number < 0)
            throw inputException();
        vcon.push_back(number);
        dcon.push_back(number);
    }
    _size = vcon.size();
}

void insert_num(std::vector<int> &V, int num)
{
    if (!std::is_sorted(V.begin(), V.end()))
    {
        std::cerr << "Vector is not sorted" << std::endl;
    }
    std::vector<int>::iterator it = std::lower_bound(V.begin(), V.end(), num);
    V.insert(it, num);
}

std::vector<std::pair<int, int>> makePairs(std::vector<int> &numbers)
{
    std::vector<std::pair<int, int>> pairs;
    for (size_t i = 0; i < numbers.size(); i += 2)
    {
        if (i + 1 < numbers.size())
        {
            if (numbers[i] < numbers[i + 1])
                pairs.push_back(std::make_pair(numbers[i + 1], numbers[i]));
            else
                pairs.push_back(std::make_pair(numbers[i], numbers[i + 1]));
        }
   }
   return pairs;
}


void PmergeMe::sortVcon()
{
    std::vector<std::pair<int, int>> pairs = makePairs(vcon);
    std::sort(pairs.begin(), pairs.end(), comparePairs);
    int strangler = -1;
    if (vcon.size() % 2 == 1)
        strangler = vcon[vcon.size() - 1];
    vcon.clear();
    std::vector<int> pendChain;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        if (pairs[i].second != -1)
        {
            vcon.push_back(pairs[i].first);
            pendChain.push_back(pairs[i].second);
        }
        else
            strangler = pairs[i].first;
    }
    vcon.insert(vcon.begin(), pendChain[0]);
    int last_jacob = 1;
    int k = 3;
    while (last_jacob < (int)pendChain.size())
    {
        int curr_jacob = jnum(k);
        int target = std::min(curr_jacob, (int)pendChain.size());
        for (int j = target - 1; j >= last_jacob; j--)
        {
            insert_num(vcon, pendChain[j]);
        }
        last_jacob = target;
        k++;
    }
    if (strangler != -1)
        insert_num(vcon, strangler);
}

void    PmergeMe::printVcon()
{
    for (size_t i = 0; i < vcon.size(); i++)
    {
        std::cout << " " << vcon[i];
    }
    std::cout << std::endl;
}

PmergeMe::~PmergeMe()
{
}

const char *::PmergeMe::inputException::what() const throw()
{
    return "Invalid Input!";
}