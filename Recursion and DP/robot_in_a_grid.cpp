#include <iostream>
#include <vector>
#include <list>
using namespace std;

list<pair<int, int>> find_path(
    const vector<vector<int>>& grid,
    int x, int y,
    vector<vector<bool>>& dp)
{
    int n = grid.size();
    if(max(x,y) >= n || grid[x][y] == 1)
    {
        dp[x][y] = true;
        return {};
    }

    if(dp[x][y])
    {
        // no path, already visited
        return {};
    }

    if(x == n-1 && y == n-1)
    {
        return { make_pair(x, y) };
    }

    list<pair<int, int>> bot = find_path(grid, x+1, y, dp);
    if(!bot.empty())
    {
        bot.push_front(make_pair(x, y));
        return bot;
    }

    list<pair<int, int>> right = find_path(grid, x, y+1, dp);
    if(!right.empty())
    {
        right.push_front(make_pair(x, y));
        return right;
    }
    dp[x][y] = true;
    return {};  // no path exists
}

list<pair<int, int>> find_path(const vector<vector<int>>& grid)
{
    int n = grid.size();
    if(!n || grid[0].size() != n)
        return {};

    // dp[i][j] = true is there's no path from this node
    vector<vector<bool>> dp(n+1, vector<bool>(n+1));

    return find_path(grid, 0, 0, dp);
}

void print(const list<pair<int,int>>& lst)
{
    int cnt = 0;
    for(const auto& p : lst)
        cout << '(' << p.first << "," << p.second << ')'
             << (++cnt < lst.size() ? " -> " : "");
    cout << endl;
}

int main()
{
   auto path = find_path({
       {0,0,0,1},
       {0,1,0,0},
       {1,0,0,0},
       {0,1,0,0}
   });
   print(path);

   auto path2 = find_path({
       {0,0,0,0},
       {0,1,1,0},
       {0,0,1,1},
       {0,1,0,0}
   });
   print(path2);    // no path

   auto path3 = find_path({
       {0,0,0,0},
       {0,0,0,0},
       {0,0,0,0},
       {0,0,0,0}
   });
   print(path3);
}