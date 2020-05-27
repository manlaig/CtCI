#include <iostream>
#include <vector>
#include <cmath>

// NOTE: I used 1D vector to represent a 2D matrix for performance
// 1D vector can take advantage of caches better than a 2D matrix (less cache misses)

// arr = 1D representation of a 2D square matrix
void print(std::vector<int> arr)
{
    int row_size = std::sqrt(arr.size());

    for(int i = 0; i < row_size; i++)
    {
        for(int j = 0; j < row_size; j++)
            std::cout << arr[i*row_size + j] << ' ';
        std::cout << std::endl;
    }
}

void transpose(std::vector<int>& arr)
{
    int row_size = std::sqrt(arr.size());

    for(int i = 0; i < row_size; i++)
        for(int j = i + 1; j < row_size; j++)
            std::swap(arr[i*row_size + j], arr[j*row_size + i]);
}

void reverse_columns(std::vector<int>& arr)
{
    int col_size = std::sqrt(arr.size());

    for(int i = 0; i < col_size/2; i++)
    {
        // column to swap with
        // -1 to account for 0-indexing
        int swap_with = col_size - i - 1;
        for(int j = 0; j < col_size; j++)
            std::swap(arr[j*col_size + i], arr[j*col_size + swap_with]);
    }
}

inline void rotate_matrix(std::vector<int>& arr)
{
    transpose(arr);
    reverse_columns(arr);
}

int main()
{
    std::vector<int> arr = {1,2,3,4,5,6,7,8,9};
    std::cout << "before:" << std::endl;
    print(arr);
    rotate_matrix(arr);
    std::cout << "after:" << std::endl;
    print(arr);
    std::cout << std::endl;

    std::vector<int> arr2 = {1,2,3,4};
    std::cout << "before:" << std::endl;
    print(arr2);
    rotate_matrix(arr2);
    std::cout << "after:" << std::endl;
    print(arr2);
    std::cout << std::endl;

    std::vector<int> arr3 = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    std::cout << "before:" << std::endl;
    print(arr3);
    rotate_matrix(arr3);
    std::cout << "after:" << std::endl;
    print(arr3);
    std::cout << std::endl;

    std::vector<int> arr4 = {1};
    std::cout << "before:" << std::endl;
    print(arr4);
    rotate_matrix(arr4);
    std::cout << "after:" << std::endl;
    print(arr4);
    std::cout << std::endl;

    std::vector<int> arr5 = {};
    std::cout << "before:" << std::endl;
    print(arr5);
    rotate_matrix(arr5);
    std::cout << "after:" << std::endl;
    print(arr5);
}