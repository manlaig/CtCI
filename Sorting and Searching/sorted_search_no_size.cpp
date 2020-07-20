#include <iostream>
#include <vector>

struct Listy
{
    int elementAt(int i)
    {
        if(i < 0 || i >= arr.size())
            return -1;
        return arr[i];
    }

    Listy() : arr({1,2,3,4,6,7,10,11,12,14,16}) {}

private:
    std::vector<int> arr;
};

int main()
{
    Listy lst;
    int size = 1;
    
    while(lst.elementAt(size) != -1)
        size *= 2;
    
    while(lst.elementAt(--size) == -1);

    int target = -1;
    std::cout << "Number to look for: ";
    std::cin >> target;

    int low = 0;
    int high = size;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(lst.elementAt(mid) == target)
        {
            std::cout << "At index: " << mid << std::endl;
            break;
        }
        else if(lst.elementAt(mid) > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
}