#include <iostream>
#include <stack>

namespace Bit
{
    void print(int num)
    {
        std::stack<char> s;
        while(num > 0)
        {
            s.push(num % 2);
            num /= 2;
        }
        while(s.size())
        {
            std::cout << ((int) s.top());
            s.pop();
        }
        std::cout << std::endl;
    }
}