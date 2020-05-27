#include <iostream>
#include <map>

/*
 * NOTE: compile with C++11
 * execute the below command to run:
 * c++ -std=c++11 Arrays\ and\ Strings/check_permutation.cpp && ./a.out
 */
bool check_permutation(const std::string& s1, const std::string& s2)
{
    // frequency of letters in s1
    std::map<char, int> freq;
    
    // counting how many from each letter s1 has
    for(int i = 0; i < s1.size(); i++)
        freq[s1[i]] = freq.find(s1[i]) == freq.end() ? 1 : freq[s1[i]] + 1;

    // checking off which s1's letter does s2 also contain
    // we do -1 because a letter can occur more than once
    for(int i = 0; i < s2.size(); i++)
        if(freq.find(s2[i]) != freq.end() && freq[s2[i]] > 0)
            freq[s2[i]] -= 1;
        else
            return false;

    // edge case where s1 has extra letters where s2 doesn't have
    for(std::pair<char, int> p : freq)
        if(p.second != 0)
            return false;
    return true;
}

int main()
{
    // 1 is true, 0 is false
    std::cout << check_permutation("hi", "ih") << std::endl;
    std::cout << check_permutation("hello", "ehlol") << std::endl;
    std::cout << check_permutation("hello", "ehlel") << std::endl;
    std::cout << check_permutation("world", "") << std::endl;
}