#include <iostream>
#include <vector>

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