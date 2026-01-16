#include "PmergeMe.hpp"

void insert_num(std::deque<int> &D, int num)
{
    if (std::adjacent_find(D.begin(), D.end(), std::greater<int>()) != D.end())
    {
        std::cerr << "Deque is not sorted" << std::endl;
    }
    std::deque<int>::iterator it = std::lower_bound(D.begin(), D.end(), num);
    D.insert(it, num);
}

std::deque<std::pair<int, int> > makePairs(std::deque<int> &numbers)
{
    std::deque<std::pair<int, int> > pairs;
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

int jnum(int num)
{
    if (num == 0)
        return 0;
    else if (num == 1)
        return 1;
    else
        return (jnum(num - 1) + 2 * jnum(num -2));
}

bool comparePairs(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
    return a.first < b.first;
}

void PmergeMe::sortDcon()
{
    std::deque<std::pair<int, int> > pairs = makePairs(dcon);
    std::sort(pairs.begin(), pairs.end(), comparePairs);
    int strangler = -1;
    if (dcon.size() % 2 == 1)
        strangler = dcon[dcon.size() - 1];
    dcon.clear();
    std::deque<int> pendChain;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        if (pairs[i].second != -1)
        {
            dcon.push_back(pairs[i].first);
            pendChain.push_back(pairs[i].second);
        }
        else
            strangler = pairs[i].first;
    }
    dcon.push_front(pendChain[0]);
    int last_jacob = 1;
    int k = 3;
    while (last_jacob < (int)pendChain.size())
    {
        int curr_jacob = jnum(k);
        int target = std::min(curr_jacob, (int)pendChain.size());
        for (int j = target - 1; j >= last_jacob; j--)
        {
            insert_num(dcon, pendChain[j]);
        }
        last_jacob = target;
        k++;
    }
    if (strangler != -1)
        insert_num(dcon, strangler);
}

void    PmergeMe::printDcon()
{
    for (size_t i = 0; i < dcon.size(); i++)
    {
        std::cout << " " << dcon[i];
    }
    std::cout << std::endl;
}