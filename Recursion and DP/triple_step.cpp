#include <iostream>

int triple_step(int n)
{
    if(n <= 3)
        return std::max(n, 0);
    int one = 1;
    int two = 2;
    int three = 4;  // [1,1,1], [1,2], [2,1], [3]

    for(int i = 4; i <= n; i++)
    {
        int temp = one + two + three;
        one = two;
        two = three;
        three = temp;
    }
    return three;
}

int main()
{
    // [1, 1, 1, 1], [1, 2, 1, 1], [2, 1, 1, 1]
    // [1, 1, 2, 1], [1, 1, 1, 2], [3, 1], [1, 3]
    std::cout << triple_step(4) << std::endl;

    // number of ways to run up to 4 stairs times 2 and
    // minus 1 since [1,1,1,1,1] will be double-counted
    std::cout << triple_step(5) << std::endl;
    std::cout << triple_step(6) << std::endl;
}