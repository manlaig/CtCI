#include <iostream>

// size is telling us how much to copy, we can't just loop until the end of str (it has reserved space at the end)
void URLify(std::string& str, int size)
{
    // out is just a string of spaces, given that str has enough space in it
    std::string out(str.size(), ' ');
    for(int i = 0, out_index = 0 ; i < size; i++, out_index++)
    {
        if(str[i] != ' ')
            out[out_index] = str[i];
        else
        {
            // we don't copy the space, instead we put %20,
            // we must increment by 2 because it's automatically incremented by 1 at the end of loop
            out[out_index] = '%';
            out[out_index+1] = '2';
            out[out_index+2] = '0';
            out_index += 2;
        }
    }
    str = out;
}

int main()
{
    std::string str = "Mr John Smith    ";
    URLify(str, 13);
    std::cout << str << std::endl;
    
    std::string str2 = "hello world  ";
    URLify(str2, 11);
    std::cout << str2 << std::endl;

    std::string str3 = " hi  ";
    URLify(str3, 3);
    std::cout << str3 << std::endl;
}