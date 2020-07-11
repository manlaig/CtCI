#include <iostream>
#include <vector>

int coins(int n)
{
    std::vector<int> coins = {1, 5, 10, 25};
    std::vector<int> dp(n+1);
    dp[0] = 0;
    for(int i : coins)
        dp[i] = 1;

    for(int i = 1; i <= n; i++)
    {
        if(!dp[i])
            continue;
        for(int coin : coins)
            if(i + coin <= n)
                dp[i+coin] += dp[i];
    }
    return dp[n];
}

int main()
{
    std::cout << coins(6) << std::endl;     // [1,5], [5,1], [1,1,1,1,1,1]
    std::cout << coins(7) << std::endl;     // [1,1,5], [5,1,1], [1,5,1], [1,1,1,1,1,1,1]
    std::cout << coins(10) << std::endl;
}