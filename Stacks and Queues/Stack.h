#include <iostream>
#include "../Linked Lists/Node.h"

class Stack
{
    Node* head;
public:
    int size;
    Stack() : head(0), size(0) {}
    ~Stack();
    int peek();
    void push(int val);
    int pop();
    void print();
};

Stack::~Stack()
{
    while(head)
    {
        Node* temp = head->next;
        delete head;
        head = head->next;
    }
}

int Stack::peek()
{
    return head ? head->val : -1;
}

void Stack::push(int val)
{
    Node* temp = new Node(val);
    temp->next = head;
    head = temp;
    size++;
}

int Stack::pop()
{
    if(!head)
        return -1;
    int out = head->val;
    Node* temp = head->next;
    delete head;
    head = temp;
    size--;
    return out;
}

void Stack::print()
{
    Node* curr = head;
    while(curr)
    {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}