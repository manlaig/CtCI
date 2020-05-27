#include <iostream>
#include <map>

// NOTE: compile with C++11
bool palindrome_permutation(std::string str)
{
    std::map<char, int> freq;
    for(int i = 0; i < str.size(); i++)
    {
        if(std::isalpha(str[i]))
            freq[str[i]] = freq.find(str[i]) == freq.end() ? 1 : freq[str[i]] + 1;
    }

    bool odd = false;
    for(std::pair<char, int> p : freq)
        if(p.second % 2 != 0 && !odd)
            odd = true;
        else if(p.second % 2 != 0)
            return false;
    return true;
}

int main()
{
    std::cout << palindrome_permutation("heeh") << std::endl;
    std::cout << palindrome_permutation("hehe") << std::endl;
    std::cout << palindrome_permutation("heheh") << std::endl;
    std::cout << palindrome_permutation("hehheh") << std::endl;
    std::cout << palindrome_permutation("tact coa") << std::endl;
    std::cout << palindrome_permutation("tact coy") << std::endl;
    std::cout << palindrome_permutation("tact ?  coa") << std::endl;
}