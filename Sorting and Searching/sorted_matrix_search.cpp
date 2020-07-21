#include <iostream>
#include <vector>
using namespace std;

pair<int, int> search(const vector<vector<int>>& mat, int target)
{
    /*
        1 5 7
        3 8 10
        7 9 11
    */
    int m = mat.size()-1;
    if(!m)
        return {-1,-1};
    int n = mat[0].size()-1;
    if(!n)
        return {-1,-1};
    
    while(n && mat[0][n] > target)
        n /= 2;
    while(n+1 < mat[0].size() && mat[0][n+1] < target)
        n++;

    while(m && mat[m][0] > target)
        m /= 2;
    while(m+1 < mat.size() && mat[m+1][0] < target)
        m++;

    cout << "bounds: " << m << " by " << n << endl;
    for(int row = m; row >= 0; row--)
    for(int col = n; col >= 0; col--)
    {
        if(mat[row][col] == target)
        {
            return {row, col};
        }
    }
    return {-1,-1};
}

int main()
{
    {
        auto p = search({
            {1, 5, 7},
            {3, 8, 10},
            {7, 9, 11}
        },8);
        cout << p.first << " " << p.second << endl;
    }
    {
        auto p = search({
            {1, 5, 7},
            {3, 8, 10},
            {7, 9, 11}
        },5);
        cout << p.first << " " << p.second << endl;
    }
    {
        auto p = search({
            {1, 5, 7},
            {3, 8, 10},
            {7, 9, 11}
        },9);
        cout << p.first << " " << p.second << endl;
    }
    {
        auto p = search({
            {1, 5, 7},
            {3, 8, 10},
            {7, 9, 11}
        },1);
        cout << p.first << " " << p.second << endl;
    }
}