#include <iostream>

int multiply(int a, int b, int sum=0)
{
    if(b <= 0)
        return sum;
    else
        return multiply(a, b-1, sum+a);
}

int main()
{
    std::cout << multiply(4, 5) << std::endl;
    std::cout << multiply(2, 8) << std::endl;
    std::cout << multiply(2, 0) << std::endl;
    std::cout << multiply(0, 5) << std::endl;
}