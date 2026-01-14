#include "PmergeMe.hpp"

// std::vector<int> insert_num(std::vector<int> &V, int num)
// {
//     if (!std::is_sorted(V.begin(), V.end()))
//     {
//         std::cerr << "Vector is not sorted" << std::endl;
//         return V;
//     }
//     std::vector<int>::iterator it = std::lower_bound(V.begin(), V.end(), num);
//     V.insert(it, num);
//     return (V);
// }

// std::vector<std::pair<int, int>> makePairs(std::vector<int> &numbers)
// {
//     std::vector<std::pair<int, int>> pairs;
//     for (size_t i = 0; i < numbers.size(); i += 2)
//     {
//         if (i + 1 < numbers.size())
//         {
//             if (numbers[i] < numbers[i + 1])
//                 pairs.push_back(std::make_pair(numbers[i + 1], numbers[i]));
//             else
//                 pairs.push_back(std::make_pair(numbers[i], numbers[i + 1]));
//         }
//         else
//             pairs.push_back(std::make_pair(numbers[i], -1));
//    }
//    return pairs;
// }

// int jnum(int num)
// {
//     if (num == 0)
//         return 0;
//     else if (num == 1)
//         return 1;
//     else
//         return (jnum(num - 1) + 2 * jnum(num -2));
// }

int main(int ac, char **av)
{
    try
    {
        if (ac != 2)
            throw PmergeMe::inputException();
        std::string input = *(++av);
        PmergeMe algo(input);
        algo.sortVcon();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    // std::vector<int> numbers = {42, 7, 12, 89, 5, 23, 4};
    // std::vector<std::pair<int, int>> pairs = makePairs(numbers);
    // int strangler;
    // std::vector<int> mainChain;
    // std::vector<int> pendChain;
    // for (size_t i = 0; i < pairs.size(); i++)
    // {
    //     if (pairs[i].second != -1)
    //     {
    //         mainChain.push_back(pairs[i].first);
    //         pendChain.push_back(pairs[i].second);
    //     }
    //     else
    //         strangler = pairs[i].first;
    // }
    // // will be changed later with a custom sorting
    // std::sort(mainChain.begin(), mainChain.end());
    // mainChain.insert(mainChain.begin(), pendChain[0]);
    // int last_jacob = 1;
    // int k = 3;
    // while (last_jacob < pendChain.size())
    // {
    //     int curr_jacob = jnum(k);
    //     int target = std::min(curr_jacob, (int)pendChain.size());
    //     for (size_t j = target - 1; j >= last_jacob; j--)
    //     {
    //         mainChain = insert_num(mainChain, pendChain[j]);
    //     }
    //     last_jacob = target;
    //     k++;
    // }
    // if (numbers.size() % 2 == 1)
    //     mainChain = insert_num(mainChain, strangler);
    return (0);
}