#include <iostream>
#include <vector>

/*
    If the input array is sorted and all distinct values,
    then a good observation is that if arr[mid] > mid,
    then a magic index can't exist on the left side,
    since both the index and the values will be increasing
    But, that's not the case if the input has duplicates
*/

int magic_index(const std::vector<int>& arr)
{
    int low = 0;
    int high = arr.size()-1;

    while(low <= high)
    {
        int mid = (high+low) / 2;

        if(arr[mid] == mid)
            return mid;
        else if(arr[mid] > mid)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

// Follow up: what if not distinct values?
// Answer: Then, we can no longer solve it in O(logN) time

int main()
{
    std::cout << magic_index({0, 2, 4, 5, 6, 7, 8, 10}) << std::endl;
    std::cout << magic_index({1, 2, 3, 4, 5}) << std::endl;
    std::cout << magic_index({-12, -11, -4, 0, 1, 5, 9}) << std::endl;
}