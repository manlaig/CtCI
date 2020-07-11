#include <iostream>
#include <vector>
#include <stack>
#include <list>
using namespace std;

/////////////////////////////////// Solution 1 ///////////////////////////////////
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

/////////////////////////////////// Solution 2 ///////////////////////////////////
list<pair<int,int>> find_path_DFS(const vector<vector<int>>& grid)
{
    int n = grid.size();
    if(!n || grid[0].size() != n)
        return {};

    stack<list<pair<int,int>>> s;
    s.push({make_pair(0, 0)});

    while(!s.empty())
    {
        auto lst = s.top();
        s.pop();

        pair<int, int> curr = lst.back();
        if(curr.first == n-1 && curr.second == n-1)
            return lst;

        int bot = 0;
        if(curr.second+1 < n && !grid[curr.first][curr.second+1])
        {
            bot = 1;
            lst.push_back(make_pair(curr.first, curr.second+1));
            s.push(lst);
        }
        if(curr.first+1 < n && !grid[curr.first+1][curr.second])
        {
            if(bot)
                lst.pop_back();
            lst.push_back(make_pair(curr.first+1, curr.second));
            s.push(lst);
        }
    }
    return {};
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
    vector<vector<int>> grid1 = {
        {0,0,0,1},
        {0,1,0,0},
        {1,0,0,0},
        {0,1,0,0}
    };
    print(find_path(grid1));
    print(find_path_DFS(grid1));

    vector<vector<int>> grid2 = {
        {0,0,0,0},
        {0,1,1,0},
        {0,0,1,1},
        {0,1,0,0}
    };
    print(find_path(grid2));    // no path
    print(find_path_DFS(grid2));    // no path

    vector<vector<int>> grid3 = {
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };
    print(find_path(grid3));    // no path
    print(find_path_DFS(grid3));    // no path
}