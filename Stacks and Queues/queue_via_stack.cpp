#include <iostream>
#include "Stack.h"

// this is a public class, just to simplify debugging and printing
struct queue_via_stack
{
    // s2 is used as a temporary storage
    Stack *s1, *s2;   
    queue_via_stack() : s1(new Stack()), s2(new Stack()) {}
    ~queue_via_stack();
    void add(int val);
    int remove();
};

queue_via_stack::~queue_via_stack()
{
    delete s1;
    delete s2;
}

void queue_via_stack::add(int val)
{
    s1->push(val);
}

int queue_via_stack::remove()
{
    while(s1->size)
        s2->push(s1->pop());

    int out = s2->pop();

    while(s2->size)
        s1->push(s2->pop());
    return out;
}

int main()
{
    queue_via_stack q;
    q.add(1);
    q.add(2);
    q.add(3);
    q.s1->print();

    std::cout << q.remove() << std::endl;
    std::cout << q.remove() << std::endl;
    std::cout << q.remove() << std::endl;
    std::cout << q.remove() << std::endl;
}