#include <iostream>
#include "Stack.h"

// this question is done very similar to the previous question
// about implementing a queue using 2 stacks

struct sort_stack
{
    // s2 is a temporary storage stack
    Stack *s1, *s2;
    sort_stack() : s1(new Stack()), s2(new Stack()) {}
    ~sort_stack();

    void push(int val);
    int pop();
};

sort_stack::~sort_stack()
{
    delete s1;
    delete s2;
}

void sort_stack::push(int val)
{
    while(val > s1->peek() && s1->size > 0)
        s2->push(s1->pop());
    s1->push(val);
    while(s2->size)
        s1->push(s2->pop());
}

int sort_stack::pop()
{
    return s1->pop();
}

int main()
{
    sort_stack s;
    s.push(5);
    s.push(8);
    s.push(3);
    s.push(1);
    s.push(2);

    s.s1->print();
    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;
}