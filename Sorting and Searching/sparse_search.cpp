#include <iostream>
#include <vector>
#include <string>

int search(const std::vector<std::string>& arr, const std::string& target, int low, int high)
{
    if(low > high)
        return -1;

    int mid = low + (high - low) / 2;
    
    int res = arr[mid].compare(target);
    if(res == 0)
        return mid;
    else if(arr[mid].size() == 0)
        return std::max(search(arr, target, 0, mid-1), search(arr, target, mid+1, high));
    else if(res > 0)
        return search(arr, target, mid+1, high);
    else
        return search(arr, target, low, mid-1);
}

int search(const std::vector<std::string>& arr, const std::string& target)
{
    return search(arr, target, 0, arr.size()-1);
}

int main()
{
    std::cout << search({"","","abc","","","bcd","","","cde"}, "cd") << std::endl;
    std::cout << search({"","","abc","","","bcd","","","cde"}, "cde") << std::endl;
    std::cout << search({"","","abc","","","bcd","","","cde"}, "bfe") << std::endl;
    std::cout << search({"","","abc","","","bcd","","","cde"}, "bcd") << std::endl;
    std::cout << search({"","","abc","","","bcd","","","cde"}, "abc") << std::endl;
    std::cout << search({"","","abc","","","bcd","","","cde"}, "") << std::endl;
}