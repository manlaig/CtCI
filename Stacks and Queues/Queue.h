#include <iostream>
#include "../Linked Lists/Node.h"

class Queue
{
    Node *head, *tail;
    int size;
public:
    Queue() : head(0), tail(0), size(0) {}
    ~Queue();
    int peek();
    void add(int val);
    int remove();
    void print();
};

Queue::~Queue()
{
    while(head)
    {
        Node* temp = head->next;
        delete head;
        head = head->next;
    }
    tail = 0;
}

int Queue::peek()
{
    return head ? head->val : -1;
}

void Queue::add(int val)
{
    Node* temp = new Node(val);
    if(!size)
        tail = head = temp;
    else
    {
        tail->next = temp;
        tail = temp;
    }
    size++;
}

int Queue::remove()
{
    if(!head)
        return -1;
    int out = head->val;
    Node* temp = head->next;
    delete head;
    head = temp;
    size--;

    if(!size)
        tail = 0;

    return out;
}

void Queue::print()
{
    Node* curr = head;
    while(curr)
    {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}