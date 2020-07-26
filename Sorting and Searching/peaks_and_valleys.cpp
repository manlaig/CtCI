#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> arrange(const vector<int>& arr)
{
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    for(int num : arr)
    {
        min_heap.push(num);
        max_heap.push(num);
    }
    vector<int> out;
    out.reserve(arr.size());
    bool peak = true;
    for(int i = 0; i < arr.size(); i++)
    {
        if(peak)
        {
            out.push_back(max_heap.top());
            max_heap.pop();
        }
        else
        {
            out.push_back(min_heap.top());
            min_heap.pop();
        }
        peak = !peak;
    }
    return out;
}

int main()
{
    {
        for(int num : arrange({5,3,1,2,3}))
            cout << num << " ";
        cout << endl;
    }
    {
        for(int num : arrange({1,2,3,4,5}))
            cout << num << " ";
        cout << endl;
    }
    {
        for(int num : arrange({5,4,3,2,1}))
            cout << num << " ";
        cout << endl;
    }
    {
        for(int num : arrange({1}))
            cout << num << " ";
        cout << endl;
    }
    {
        for(int num : arrange({}))
            cout << num << " ";
        cout << endl;
    }
}