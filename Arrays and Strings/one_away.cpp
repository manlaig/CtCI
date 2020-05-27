#include <iostream>

// levenstein distance is the minimum # of operations (1 of 3) needed to turn s1 to s2
int levenstein_distance(const std::string& s1, const std::string& s2, int s1_index = 0, int s2_index = 0)
{
    if(s1_index >= s1.size())
        return s2.size() - s2_index;

    if(s2_index >= s2.size())
        return s1.size() - s1_index;

    if(s1[s1_index] == s2[s2_index])
        return levenstein_distance(s1, s2, s1_index+1, s2_index+1);

    // minimum between inserting s2[s2_index] into s1 and deleting s2[s2_index] from s2
    int insert_min = std::min(levenstein_distance(s1, s2, s1_index+1, s2_index), levenstein_distance(s1, s2, s1_index, s2_index+1));
    // minimum between inserting and replacing the character
    // we add +1 to account for the operation
    return std::min(insert_min, levenstein_distance(s1, s2, s1_index+1, s2_index+1)) + 1;
}

bool one_away(const std::string& s1, const std::string& s2)
{
    return levenstein_distance(s1, s2) <= 1;
}

int main()
{
    std::cout << one_away("hello", "helo") << std::endl;
    std::cout << one_away("hello", "hlo") << std::endl;
    std::cout << one_away("hello", "world") << std::endl;
    std::cout << one_away("h", "") << std::endl;
    std::cout << one_away("h", "e") << std::endl;
    std::cout << one_away("h", "he") << std::endl;
    std::cout << one_away("pale", "ple") << std::endl;
    std::cout << one_away("pales", "pale") << std::endl;
    std::cout << one_away("pale", "bale") << std::endl;
    std::cout << one_away("pale", "bake") << std::endl;
}