#include <iostream>
#include <vector>

struct Box
{
    int h, w, l;
    Box(int hh, int ww, int ll) : h(hh), w(ww), l(ll) {}
};

bool operator<(Box b1, Box b2)
{
    return b1.h < b2.h && b1.w < b2.w && b1.l < b2.l;
}

int tallest_stack(std::vector<Box> arr)
{
    sort(arr.begin(), arr.end());
    // dp[i][j] = height of stack starting at i and ending at j
    std::vector<std::vector<int>> dp(arr.size(), std::vector<int>(arr.size()));

    int out = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr.size(); j++)
        {
            int tallest = 0;
            for(int k = 0; k < arr.size(); k++)
            {
                if(arr[k] < arr[j])
                    tallest = std::max(tallest, dp[i][k]);
            }
            dp[i][j] = tallest + arr[j].h;
            out = std::max(out, dp[i][j]);
        }
    }
    return out;
}

int main()
{
    std::cout << tallest_stack({{10,10,10}, {12,12,12}, {3,3,3}, {2,2,2}}) << std::endl;
    std::cout << tallest_stack({{2,2,2}, {3,0,0}, {20,10,10}, {12,12,32}}) << std::endl;
}