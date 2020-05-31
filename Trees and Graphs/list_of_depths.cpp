#include <iostream>
#include <queue>
#include "Tree.h"
#include "../Linked Lists/Node.h"

Node** list_of_depths(BST::Node* root)
{
    if(!root)
        return nullptr;

    int height = BST::get_height(root);
    Node* *out = new Node*[height];
    for(int i = 0; i < height; i++)
        out[i] = 0;
    
    std::queue<std::pair<BST::Node*, int> > q;
    q.push(std::make_pair(root, 0));

    while(q.size())
    {
        std::pair<BST::Node*, int> top = q.front();
        q.pop();
        LL::addToTail(out[top.second], top.first->val);

        if(top.first->left)
            q.push(std::make_pair(top.first->left, top.second+1));
        if(top.first->right)
            q.push(std::make_pair(top.first->right, top.second+1));
    }

    return out;
}

int main()
{
    BST::Node* root = 0;
    /*
                5
        3               7
            4               9
                5
    */
    BST::add(root, 5);
    BST::add(root, 3);
    BST::add(root, 7);
    BST::add(root, 4);
    BST::add(root, 5);
    BST::add(root, 9);

    Node** out = list_of_depths(root);
    for(int i = 0; i < BST::get_height(root); i++)
    {
        std::cout << "Depth: " << i << ": ";
        LL::print(out[i]);
    }
}