#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(const vector<int>& left, const vector<int>& right)
{
    vector<int> out;
    out.reserve(left.size() + right.size());
    int i = 0;
    int j = 0;
    while(i < left.size() && j < right.size())
    {
        if(left[i] < right[j])
            out.push_back(left[i++]);
        else
            out.push_back(right[j++]);
    }
    while(i < left.size())
    {
        out.push_back(left[i++]);
    }
    while(j < right.size())
    {
        out.push_back(right[j++]);
    }
    return out;
}

vector<int> merge_sort(vector<int>& arr, int start, int end)
{
    if(!arr.size())
        return {};
    if(start >= end)
        return {arr[start]};
    int mid = (start+end) / 2;
    auto left = merge_sort(arr, start, mid);
    auto right = merge_sort(arr, mid+1, end);
    return merge(left, right);
}

int main()
{
    {
        vector<int> arr = {1,4,2,8,5,6,3};
        for(int num : merge_sort(arr, 0, arr.size()-1))
            cout << num << " ";
        cout << endl;
    }
    {
        vector<int> arr = {3,2,1,0};
        for(int num : merge_sort(arr, 0, arr.size()-1))
            cout << num << " ";
        cout << endl;
    }
    {
        vector<int> arr = {6,5,4,3,2,1,0};
        for(int num : merge_sort(arr, 0, arr.size()-1))
            cout << num << " ";
        cout << endl;
    }
    {
        vector<int> arr = {};
        for(int num : merge_sort(arr, 0, arr.size()-1))
            cout << num << " ";
        cout << endl;
    }
}