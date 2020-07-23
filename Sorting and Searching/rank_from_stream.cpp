#include <iostream>
#include <vector>

struct Node
{
    int val;
    int smaller;
    Node *left, *right;

    Node(int v, int s) : val(v), smaller(s), left(0), right(0) {}
};

void add(Node*& head, int val, int smaller=0)
{
    if(!head)
        head = new Node(val, smaller);
    if(head->val == val)
        return;
    else if(head->val < val)
        add(head->right, val, head->smaller + 1);
    else
    {
        add(head->left, val, smaller);
    }
}

int find(Node* head, int val)
{
    if(head->val == val)
        return head->smaller;
    else if(head->val < val)
        return find(head->right, val);
    return find(head->left, val);
}

struct Stream
{
    Node* head = 0;
    void track(int num)
    {
        add(head, num);
    }

    int rank(int num)
    {
        return find(head, num);
    }
};

int main()
{
    {
        Stream str;
        for(int num : {1,2,3,4,5,6,7})
        {
            str.track(num);
        }
        std::cout << str.rank(3) << std::endl;
        std::cout << str.rank(5) << std::endl;
        std::cout << str.rank(7) << std::endl << std::endl;
    }
    {
        Stream str;
        for(int num : {7,6,5,4,3,2,1})
        {
            str.track(num);
        }
        std::cout << str.rank(3) << std::endl;
        std::cout << str.rank(5) << std::endl;
        std::cout << str.rank(7) << std::endl << std::endl;
    }
    {
        Stream str;
        for(int num : {1,5,3,2,6,7})
        {
            str.track(num);
        }
        std::cout << str.rank(3) << std::endl;
        std::cout << str.rank(5) << std::endl;
        std::cout << str.rank(7) << std::endl << std::endl;
    }
}