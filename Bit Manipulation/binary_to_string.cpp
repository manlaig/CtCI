#include <iostream>
#include <string>

std::string binary_to_string(double num)
{
    std::string out = "0.";

    int count = 0;
    double div = 1./2;
    while(count++ < 25 && num != 0.0)
    {
        if(div <= num)
        {
            num -= div;
            out += '1';
        }
        div /= 2; 
    }
    return out;
}

int main()
{
    std::cout << binary_to_string(0.50) << std::endl;
    std::cout << binary_to_string(0.75) << std::endl;
    std::cout << binary_to_string(0.825) << std::endl;
    std::cout << binary_to_string(0.333) << std::endl;
}