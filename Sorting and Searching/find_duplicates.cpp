#include <unordered_set>
#include <vector>
#include <iostream>

std::unordered_set<int> findDuplicates(std::vector<int> arr)
{
    std::unordered_set<int> out;
    // 1 2 5 4 4 3
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[abs(arr[i])-1] < 0)
        {
            out.insert(abs(arr[i]));
        }
        else
            arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
    }
    return out;
}

int main()
{
    {
        auto out = findDuplicates({1,2,5,4,4,3});
        for(int dup : out)
            std::cout << dup << " ";
        std::cout << std::endl;
    }
    {
        auto out = findDuplicates({1,2,5,4,3,3,3});
        for(int dup : out)
            std::cout << dup << " ";
        std::cout << std::endl;
    }
    {
        auto out = findDuplicates({1,1,2,5,4,3});
        for(int dup : out)
            std::cout << dup << " ";
        std::cout << std::endl;
    }
    {
        auto out = findDuplicates({1,1,2,2,5,4,4,3});
        for(int dup : out)
            std::cout << dup << " ";
        std::cout << std::endl;
    }
    {
        auto out = findDuplicates({1,1,1,1,1,1,1,2,2,5,4,4,3});
        for(int dup : out)
            std::cout << dup << " ";
        std::cout << std::endl;
    }
    {
        auto out = findDuplicates({1,1,1,1,1,1,2,2,5,4,4,3});
        for(int dup : out)
            std::cout << dup << " ";
        std::cout << std::endl;
    }
    {
        auto out = findDuplicates({1,2,3,4,5,6,7});
        for(int dup : out)
            std::cout << dup << " ";
        std::cout << std::endl;
    }
}