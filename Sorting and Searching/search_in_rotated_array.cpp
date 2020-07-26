#include <iostream>
#include <vector>

/*
    The logic in this problem is that you first implement normal binary search,
    then ask "what are the cases when I should choose the opposite side?"
*/

int search(const std::vector<int>& arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(arr[mid] == target)
            return mid;
        else if(arr[mid] > target)
        {
            // 5 6 7 8 1 2 3
            if(arr[mid] > arr[high] && target <= arr[high])
                low = mid+1;
            else
                high = mid-1;
        }
        else
        {
            // 5 6 1 2 3
            if(arr[mid] < arr[low] && target >= arr[low])
                high = mid-1;
            else
                low = mid+1;
        }
    }
    return -1;
}

int main()
{

}