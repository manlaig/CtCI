#include <iostream>
#include <vector>

std::vector<int> merge(const std::vector<int>& v1, const std::vector<int>& v2)
{
    int n1 = v1.size();
    int n2 = v2.size();

    int i1 = 0;
    int i2 = 0;

    std::vector<int> out;
    out.reserve(n1 + n2);
    while(i1 < n1 && i2 < n2)
    {
        if(v1[i1] < v2[i2])
            out.push_back(v1[i1++]);
        else if(v1[i1] > v2[i2])
            out.push_back(v2[i2++]);
        else
        {
            out.push_back(v1[i1++]);
            out.push_back(v2[i2++]);
        }
    }
    while(i1 < n1)
        out.push_back(v1[i1++]);
    while(i2 < n2)
        out.push_back(v2[i2++]);
    return out;
}

int main()
{
    std::vector<int> out = merge({1,3,5,7}, {2,4,6,8,10,12,14});
    for(int i : out)
        std::cout << i << " ";
    std::cout << std::endl;
}
