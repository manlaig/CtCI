#include <iostream>
#include <string>

void parens(std::string str, int max_allowed, int remain, int open=0, int close=0)
{
    if(remain <= 0)
    {
        std::cout << str << std::endl;
        return;
    }
    if(open < max_allowed)
        parens(str + '(', max_allowed, remain-1, open+1, close);
    if(open > close)
        parens(str + ')', max_allowed, remain-1, open, close+1);
}

int main()
{
   int n = 3;
   parens("", n, 2*n);

   int n2 = 4;
   parens("", n2, 2*n2);
}