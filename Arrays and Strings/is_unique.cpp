#include <iostream>
#include <set>

bool is_unique(const std::string& str)
{
    std::set<char> occurred;
    for(int i = 0; i < str.size(); i++)
    {
        if(occurred.find(str[i]) == occurred.end())
            occurred.insert(str[i]);
        else
            return false;
    }
    return true;
}

int main()
{
    std::cout << is_unique("hel") << std::endl;
    std::cout << is_unique("hell") << std::endl;
    std::cout << is_unique("helol") << std::endl;
    std::cout << is_unique("") << std::endl;
}