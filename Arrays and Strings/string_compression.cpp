#include <iostream>

std::string string_compression(const std::string& str)
{
    std::string output;
    // extra capacity for optimizing string concatenation
    output.reserve(25);

    // what is the last occurred character
    char last = 0;
    // how many of consequent occurences of 'last'
    int count = -1;

    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] != last)
        {
            // we don't write to output for the first character
            if(count > -1)
            {
                output += last;
                output += std::to_string(count);
            }

            // reset
            last = str[i];
            count = 1;
        }
        else
            count += 1;
    }
    if(count > -1)
    {
        output += last;
        output += std::to_string(count);
    }
    return output.size() < str.size() ? output : str;
}

int main()
{
    std::cout << string_compression("aaaabbbcdd") << std::endl;
    std::cout << string_compression("") << std::endl;
    std::cout << string_compression("abc") << std::endl;
    std::cout << string_compression("abcc") << std::endl;
    std::cout << string_compression("abccccc") << std::endl;
    std::cout << string_compression("aabcccccaaa") << std::endl;
}