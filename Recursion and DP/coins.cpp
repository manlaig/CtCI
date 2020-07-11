#include <iostream>
#include <vector>

int coins_forward(int n)
{
    std::vector<int> coins = {1, 5, 10, 25};
    std::vector<int> dp(n+1, 0);
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

int coins_back(int n)
{
    std::vector<int> coins = {1, 5, 10, 25};
    std::vector<int> dp(n+1, 0);
    dp[0] = 1;

    for(int i = 1; i <= n; i++)
    {
        for(int coin : coins)
            if(i - coin >= 0)
                dp[i] += dp[i-coin];
    }
    return dp[n];
}

int main()
{
    std::cout << coins_forward(6) << " " << coins_back(6) << std::endl;     // [1,5], [5,1], [1,1,1,1,1,1]
    std::cout << coins_forward(7) << " " << coins_back(7) << std::endl;     // [1,1,5], [5,1,1], [1,5,1], [1,1,1,1,1,1,1]
    std::cout << coins_forward(10) << " " << coins_back(10) << std::endl;
    std::cout << coins_forward(25) << " " << coins_back(25) << std::endl;
}