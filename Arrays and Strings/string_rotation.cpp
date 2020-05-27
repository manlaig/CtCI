#include <iostream>

// we are given by the problem that this function is given
// I'll just use C++ std's function
inline bool isSubstring(const std::string& src, const std::string& target)
{
    return src.find(target) != std::string::npos;
}

inline bool string_rotation(const std::string& rotated, const std::string& original)
{
    // if you append rotated to itself, then the original appears if rotated is valid
    return isSubstring(rotated + rotated, original) && rotated.size() == original.size();
}

int main()
{
    std::cout << string_rotation("erbottlewat", "bottlewater") << std::endl;
    std::cout << string_rotation("rbottlewate", "bottlewater") << std::endl;
    std::cout << string_rotation("erwat", "water") << std::endl;
    std::cout << string_rotation("erwat", "watr") << std::endl;
    std::cout << string_rotation("erwater", "water") << std::endl;
    std::cout << string_rotation("water", "water") << std::endl;
    std::cout << string_rotation("watrr", "water") << std::endl;
    std::cout << string_rotation("terwa", "water") << std::endl;
    std::cout << string_rotation("terwa", "") << std::endl;
    std::cout << string_rotation("", "water") << std::endl;
    std::cout << string_rotation("", "") << std::endl;
}