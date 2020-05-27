#include <iostream>
#include <vector>
#include <set>

// NOTE: compile with C++11 because of the foreach loop feature

// arr is a M x N matrix
void zero_matrix(std::vector<int>& arr, int M, int N)
{
    std::set<int> rows, cols;

    // save which rows and cols need to be zeroed
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            if(!arr[i * M + j])
            {
                rows.insert(i);
                cols.insert(j);
            }

    for(int i : rows)
        for(int j = 0; j < N; j++)
            arr[i * M + j] = 0;

    for(int j : cols)
        for(int i = 0; i < M; i++)
            arr[i * M + j] = 0;
}

// arr is a M x N matrix
void print(const std::vector<int>& arr, int M, int N)
{
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
            std::cout << arr[i * M + j] << ' ';
        std::cout << std::endl;
    }
}

int main()
{
    std::vector<int> arr = {1,2,0,0,5,6,7,8,9};
    std::cout << "before:" << std::endl;
    print(arr, 3, 3);
    zero_matrix(arr, 3, 3);
    std::cout << "after:" << std::endl;
    print(arr, 3, 3);
    std::cout << std::endl;

    std::vector<int> arr2 = {0,2,3,4,5,6};
    std::cout << "before:" << std::endl;
    print(arr2, 2, 3);
    zero_matrix(arr2, 2, 3);
    std::cout << "after:" << std::endl;
    print(arr2, 2, 3);
    std::cout << std::endl;

    std::vector<int> arr4 = {0};
    std::cout << "before:" << std::endl;
    print(arr4, 1, 1);
    zero_matrix(arr4, 1, 1);
    std::cout << "after:" << std::endl;
    print(arr4, 1, 1);
    std::cout << std::endl;

    std::vector<int> arr5 = {};
    std::cout << "before:" << std::endl;
    print(arr5, 0, 0);
    zero_matrix(arr5, 0, 0);
    std::cout << "after:" << std::endl;
    print(arr5, 0, 0);
}