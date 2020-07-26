#include <iostream>
#include <vector>

int partition(std::vector<int>& arr, int start, int end)
{
    int pivot = end;
    // 1 4 2 8 5 6 3
    // 1 6 2 8 5 3 4
    // 1 5 2 8 3 6 4
    // 1 8 2 3 5 6 4
    // 1 2 3 8 5 6 4
    int i = start;
    while(i < end)
    {
        if(arr[i] <= arr[end])
            i++;
        else
        {
            std::swap(arr[end], arr[end-1]);
            if(end-1 != i)
                std::swap(arr[end], arr[i]);
            end--;
        }
    }
    return end;
}

void quick_sort(std::vector<int>& arr, int start, int end)
{
    if(start >= end)
        return;
    int i = partition(arr, start, end);
    quick_sort(arr, i+1, end);
    quick_sort(arr, start, i-1);
}

int main()
{
    {
        std::vector<int> arr = {1,4,2,8,5,6,3};
        quick_sort(arr, 0, arr.size()-1);
        for(int num : arr)
            std::cout << num << " ";
        std::cout << std::endl;
    }
    {
        std::vector<int> arr = {1,1,1,1,1,1,2,2,2,2,2,1,1,1};
        quick_sort(arr, 0, arr.size()-1);
        for(int num : arr)
            std::cout << num << " ";
        std::cout << std::endl;
    }
    {
        std::vector<int> arr = {6,5,4,3,2,1,0};
        quick_sort(arr, 0, arr.size()-1);
        for(int num : arr)
            std::cout << num << " ";
        std::cout << std::endl;
    }
    {
        std::vector<int> arr = {};
        quick_sort(arr, 0, arr.size()-1);
        for(int num : arr)
            std::cout << num << " ";
        std::cout << std::endl;
    }
}