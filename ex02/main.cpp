#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac < 2)
            throw PmergeMe::inputException();
        struct timeval start, end;
        double timediff;
        std::string input = "";
        for (int i = 1; i < ac; i++)
        {
            input += av[i];
            input += " ";
        }
        PmergeMe algo(input);
        std::cout << "before: ";
        algo.printVcon();
        gettimeofday(&start, NULL);        
        algo.sortVcon();
        gettimeofday(&end, NULL);
        std::cout << "after: ";
        algo.printVcon();
        timediff = (static_cast<double>(end.tv_sec) - start.tv_sec) * 1000000.0 + 
           (static_cast<double>(end.tv_usec) - start.tv_usec);
        std::cout << "Time to process a range of " << algo._size << " in std::vector<int> : " << timediff << " us" << std::endl;
        gettimeofday(&start, NULL);        
        algo.sortDcon();
        gettimeofday(&end, NULL);
        timediff = (end.tv_sec - start.tv_sec) * 1000000.00 + (end.tv_usec - start.tv_usec);
        std::cout << "Time to process a range of " << algo._size << " in std::deque<int> : " << timediff << " us" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}