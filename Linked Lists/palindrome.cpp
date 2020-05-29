#include <iostream>
#include "Node.h"

bool palindrome(Node* head, Node*& buf)
{
    if(!head)
        return true;
    LL::addToTail(buf, head->val);
    bool ret = palindrome(head->next, buf);
    bool out = buf->val == head->val;
    Node* temp = buf;
    buf = buf->next;
    delete buf;
    return out && ret;
}

int main()
{
    Node* head = 0;

    LL::addToTail(head, 1);
    LL::addToTail(head, 2);
    LL::addToTail(head, 3);
    LL::addToTail(head, 3);
    LL::addToTail(head, 2);
    LL::addToTail(head, 1);

    Node* buf = 0;
    std::cout << palindrome(head, buf) << std::endl;
}