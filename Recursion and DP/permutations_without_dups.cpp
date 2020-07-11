#include <iostream>
#include <string>
using namespace std;

void permutations(string str, int start = 0)
{
    if(start >= str.size())
    {
        cout << str << endl;
        return;
    }
    for(int i = start; i < str.size(); i++)
    {
        swap(str[start], str[i]);
        permutations(str, start+1);
    }
}

int main()
{
    /*
        abc
        acb
        bac
        bca
        cab
        cba
    */
    permutations("abc");
}