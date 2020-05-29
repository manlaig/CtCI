#include <iostream>
#include "Stack.h"

// NOTE: compile with c++11
// run this: g++ -std=c++11 Stacks\ and\ Queues/three_in_one.cpp && ./a.out

class Three_in_one
{
    // pointer of stacks
    Stack** arr;
public:
    // compile with the -std=c++11 flag!
    Three_in_one() : arr(new Stack*[3] {new Stack(), new Stack(), new Stack()}) {}

    ~Three_in_one()
    {
        delete arr[0];
        delete arr[1];
        delete arr[2];
        delete[] arr;
    }

    template <size_t T>
    int peek()
    {
        return arr[T-1]->peek();
    }

    template <size_t T>
    void push(int val)
    {
        arr[T-1]->push(val);
    }

    template <size_t T>
    int pop()
    {
        return arr[T-1]->pop();
    }

    template <size_t T>
    void print()
    {
        arr[T-1]->print();
    }
};

int main()
{
    Three_in_one t;

    // use push<1>(25) to push value 25 into 1st stack

    t.push<1>(10);
    t.push<1>(20);
    t.push<1>(30);
    t.pop<1>();
    t.pop<1>();

    t.push<2>(20);

    t.push<3>(30);

    t.print<1>();
    t.print<2>();
    t.print<3>();
}