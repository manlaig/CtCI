#include <iostream>
#include "Node.h"

Node* sum_lists(Node* l1, Node* l2)
{
    Node* out = 0;
    int carry = 0;

    while(l1 && l2)
    {
        LL::addToTail(out, (l1->val + l2->val + carry) % 10);
        carry = (int) (l1->val + l2->val + carry) >= 10;

        l1 = l1->next;
        l2 = l2->next;
    }

    // if l1 has more digits than l2
    while(l1)
    {
        LL::addToTail(out, (l1->val + carry) % 10);
        carry = (int) (l1->val + carry) >= 10;
        l1 = l1->next;
    }

    // if l2 has more digits than l1
    while(l2)
    {
        LL::addToTail(out, (l2->val + carry) % 10);
        carry = (int) (l2->val + carry) >= 10;
        l2 = l2->next;
    }

    // the sum can result in an extra 1 digit
    if(carry)
        LL::addToTail(out, carry);

    return out;
}

int main()
{
    using namespace LL;

    // 3 -> 2 -> 1  +  4 -> 5 -> 6  =  7 -> 7 -> 7
    // 123 + 654  =  777
    Node* l1 = 0;
    addToHead(l1, 1);
    addToHead(l1, 2);
    addToHead(l1, 3);
    Node* l2 = 0;
    addToHead(l2, 6);
    addToHead(l2, 5);
    addToHead(l2, 4);
    // printed in reverse order
    Node* s4 = sum_lists(l1, l2);
    std::cout << "added in reverse: ";
    print(s4);
    std::cout << "added in forward: ";
    reverse(s4);
    print(s4);
    std::cout << std::endl;

    // 3 -> 2 -> 1  +  5 -> 6  =  8 -> 8 -> 1
    // 123 + 65 = 188
    Node* l3 = 0;
    addToHead(l3, 1);
    addToHead(l3, 2);
    addToHead(l3, 3);
    Node* l4 = 0;
    addToHead(l4, 6);
    addToHead(l4, 5);
    // printed in reverse order
    Node* s3 = sum_lists(l3, l4);
    std::cout << "added in reverse: ";
    print(s3);
    std::cout << "added in forward: ";
    reverse(s3);
    print(s3);
    std::cout << std::endl;

    // 3  +  5 -> 6  =  8 -> 6
    // 3 + 65 = 68
    Node* l5 = 0;
    addToHead(l5, 3);
    Node* l6 = 0;
    addToHead(l6, 6);
    addToHead(l6, 5);
    // printed in reverse order
    Node* s2 = sum_lists(l5, l6);
    std::cout << "added in reverse: ";
    print(s2);
    std::cout << "added in forward: ";
    reverse(s2);
    print(s2);
    std::cout << std::endl;

    // 9  +  9  =  8 -> 1
    // 9 + 9 = 18
    Node* l7 = 0;
    addToHead(l7, 9);
    Node* l8 = 0;
    addToHead(l8, 9);
    // printed in reverse order
    Node* s = sum_lists(l7, l8);
    std::cout << "added in reverse: ";
    print(s);
    std::cout << "added in forward: ";
    reverse(s);
    print(s);
}