#include <iostream>
#include <unordered_set>
using namespace std;

struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};

bool canPlace(unordered_set<pair<int, int>, pair_hash> queens, int row, int col)
{
    for(auto p : queens)
    {
        int x = p.first;
        int y = p.second;
        if(y == col || abs(x-row) == abs(y-col))
            return false;
    }
    return true;
}

void eight_queens(unordered_set<pair<int, int>, pair_hash> queens, int row=0)
{
    if(row >= 8)
    {
        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                if(queens.find(make_pair(i,j)) != queens.end())
                    cout << " Q ";
                else
                    cout << " . ";
            }
            cout << endl;
        }
        cout << "-----------------------" << endl;
    }
    for(int col = 0; col < 8; col++)
    {
        if(canPlace(queens, row, col))
        {
            queens.insert(make_pair(row, col));
            eight_queens(queens, row+1);
            queens.erase(make_pair(row, col));
        }
    }
}

int main()
{
    unordered_set<pair<int, int>, pair_hash> s;
    eight_queens(s);
}