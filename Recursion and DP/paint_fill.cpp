#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void fill(vector<vector<int>>& screen, int x, int y, int newColor)
{
    int n = screen.size();
    if(!n || screen[0].size() != n)
        return;
    if(max(x, y) >= n || screen[x][y] == newColor)
        return;

    stack<pair<int, int>> s;
    s.push(make_pair(x, y));
    int original = screen[x][y];

    while(!s.empty())
    {
        auto top = s.top();
        s.pop();
        int top_x = top.first;
        int top_y = top.second;
        screen[top_x][top_y] = newColor;

        if(top_x+1 < n && screen[top_x+1][top_y] == original)
            s.push(make_pair(top_x+1, top_y));
        if(top_x-1 >= 0 && screen[top_x-1][top_y] == original)
            s.push(make_pair(top_x-1, top_y));

        if(top_y+1 < n && screen[top_x][top_y+1] == original)
            s.push(make_pair(top_x, top_y+1));
        if(top_y-1 >= 0 && screen[top_x][top_y-1] == original)
            s.push(make_pair(top_x, top_y-1));
    }
}

int main()
{
    vector<vector<int>> s1 = {
        {0,1,1,0},
        {2,1,3,1},
        {1,1,3,1},
        {1,0,1,4}
    };
    fill(s1, 1, 1, 7);
    for(const auto& vec : s1)
    {
        for(int num : vec)
            cout << num  << " ";
        cout << endl;
    }
}