#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> insert_num(std::vector<int> V, int num)
{
    if (!std::is_sorted(V.begin(), V.end()))
    {
        std::cerr << "Vector is not sorted" << std::endl;
        return V;
    }
    std::vector<int>::iterator it = std::lower_bound(V.begin(), V.end(), num);
    V.insert(it, num);
    std::cout << "Number " << num << " was inserted succesfully" << std::endl;
    return (V);
}

std::vector<std::pair<int, int>> makePairs(std::vector<int> &numbers)
{
    std::vector<std::pair<int, int>> pairs;
    for (size_t i = 0; i < numbers.size(); i += 2)
    {

    }
}

int main()
{
    std::vector<int> numbers = {42, 7, 12, 89, 5, 23};
    size_t size = numbers.size();
    for (size_t i = 0; i < size; i++)
    {
        std::cout << i + 1 << " => [" << numbers[i] << "]" << std::endl;
    }
    std::vector<std::pair<int, int>> pairs = makePairs(numbers);
    
    return (0);
}