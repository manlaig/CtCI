#include <iostream>

int conversion(int a, int b)
{
    int count = 0;
    while(a && b)
    {
        count += a % 2 != b % 2;
        a /= 2;
        b /= 2;
    }
    while(a)
    {
        count += a % 2;
        a /= 2;
    }
    while(b)
    {
        count += b % 2;
        b /= 2;
    }
    return count;
}

int main()
{
    std::cout << conversion(8, 8) << std::endl;
    std::cout << conversion(8, 4) << std::endl;
    std::cout << conversion(12, 4) << std::endl;
    std::cout << conversion(12, 0) << std::endl;
    std::cout << conversion(12, 15) << std::endl;   // 1100, 1111
    std::cout << conversion(0, 16) << std::endl;
}