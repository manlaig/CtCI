#include <iostream>
#include <vector>
#include "Stack.h"

class SetOfPlates
{
    size_t capacity;
    int last;
public:
    std::vector<Stack*> plates;
    SetOfPlates(size_t);
    ~SetOfPlates();
    void push(int val);
    int pop();
};

SetOfPlates::SetOfPlates(size_t _capacity) : capacity(_capacity), last(0)
{
    plates.push_back(new Stack());
}

SetOfPlates::~SetOfPlates()
{
    for(int i = 0; i < plates.size(); i++)
        delete plates[i];
}

void SetOfPlates::push(int val)
{
    if(plates[last]->size < capacity)
        plates[last]->push(val);
    else
    {
        if(last >= plates.size()-1)
            plates.push_back(new Stack());
        plates[++last]->push(val);
    }   
}

int SetOfPlates::pop()
{
    int out = plates[last]->pop();
    if(!plates[last]->size && last)
        last--;
    return out;
}

int main()
{
    SetOfPlates s(2);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.plates[0]->print();
    s.plates[1]->print();
    s.plates[2]->print();

    std::cout << std::endl << "popped: " << s.pop() << std::endl;
    s.plates[0]->print();
    s.plates[1]->print();
    s.plates[2]->print();

    std::cout << "popped: " << s.pop() << std::endl;
    s.plates[0]->print();
    s.plates[1]->print();
    s.plates[2]->print();

    std::cout << "popped: " << s.pop() << std::endl;
    s.plates[0]->print();
    s.plates[1]->print();
    s.plates[2]->print();

    std::cout << "popped: " << s.pop() << std::endl;
    s.plates[0]->print();
    s.plates[1]->print();
    s.plates[2]->print();

    std::cout << "popped: " << s.pop() << std::endl;
    s.plates[0]->print();
    s.plates[1]->print();
    s.plates[2]->print();

    std::cout << "popped: " << s.pop() << std::endl;
    s.plates[0]->print();
    s.plates[1]->print();
    s.plates[2]->print();

    std::cout << "popped: " << s.pop() << std::endl;
    s.plates[0]->print();
    s.plates[1]->print();
    s.plates[2]->print();
}