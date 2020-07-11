#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// This solution is O(2^n), n is the size of elements in the array
// The power set consists of 2^n number of elements
void power_set(vector<vector<int>>& out, const vector<int>& arr, vector<int> buf, int curr=0)
{
    if(curr >= arr.size())
    {
        out.push_back(buf);
        return;
    }

    power_set(out, arr, buf, curr+1);
    buf.push_back(arr[curr]);
    power_set(out, arr, buf, curr+1);
}

vector<vector<int>> power_set(const vector<int>& arr)
{
    vector<vector<int>> set;
    set.reserve(pow(2, arr.size()));
    power_set(set, arr, {});
    return set;
}

void print(const vector<vector<int>>& arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr[i].size(); j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    {
        // including the empty set, the size is 8
        auto set = power_set({1,2,3});
        print(set);
    }
    {
        // including the empty set, the size is 16
        auto set = power_set({1,2,3,4});
        print(set);
    }
}