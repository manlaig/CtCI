#include <iostream>

/*
    Question: how would you implement a stack min function that returns the minimum element in O(1) time?

    Solution: have a member variable "min" in the Stack class. Each node in the stack will have its own "min" value.
    That min value is "propagate" upwards, meaning that each node's min value will tell us "what's the smallest value from this node until the end"
*/

struct Node
{
    int val, min;
    Node* next;
    Node(int _val, int _min, Node* _next) : val(_val), min(_min), next(_next) {}
};

void add(Node*& head, int val)
{
    head = new Node(val, std::min(val, head ? head->min : val), head);
}

void print(Node* head)
{
    while(head)
    {
        std::cout << head->val << " " << head->min << std::endl;
        head = head->next;
    }
}

int main()
{
    Node* head = 0;
    add(head, 10);
    add(head, 15);
    add(head, 20);
    add(head, 5);
    add(head, 50);
    print(head);
}