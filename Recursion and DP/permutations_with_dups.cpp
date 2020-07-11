#include <iostream>
#include <vector>
#include <set>
using namespace std;

void helper(set<vector<int>>& out, vector<int> arr, int start)
{
    if(start >= arr.size())
    {
        out.insert(arr);
        return;
    }

    for(int i = start; i < arr.size(); i++)
    {
        swap(arr[start], arr[i]);
        helper(out, arr, start+1);
    }
}

set<vector<int>> permutations(const vector<int>& arr)
{
    set<vector<int>> out;
    helper(out, arr, 0);
    return out;
}

int main()
{
    // 4 * 3 * 2 / 2 = 12 permutations
    // divide by 2 to remove permutations for the 2 threes
    auto perm = permutations({1,2,3,3});
    for(auto vec : perm)
    {
        for(int num : vec)
            cout << num  << " ";
        cout << endl;
    }
    cout << endl;

    auto perm2 = permutations({3,3,3,3,3});
    for(auto vec2 : perm2)
    {
        for(int num : vec2)
            cout << num  << " ";
        cout << endl;
    }
}