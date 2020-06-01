#include <iostream>
#include <set>
#include <list>
#include "Tree.h"

void get_level_helper(std::list<int>* out, int depth, int curr, BST::Node* root)
{
    if(!root)
        return;
    if(curr == depth)
        out->push_back(root->val);
    else
    {
        get_level_helper(out, depth, curr+1, root->left);
        get_level_helper(out, depth, curr+1, root->right);
    }
}

// depth is 0-indexed
std::list<int>* get_level(BST::Node* root, int depth)
{
    std::list<int>* out = new std::list<int>();
    get_level_helper(out, depth, 0, root);
    return out;
}

int main()
{
    BST::Node* root = 0;
    BST::add(root, 10);
    BST::add(root, 5);
    BST::add(root, 15);
    BST::add(root, 1);
    BST::add(root, 7);
    BST::add(root, 13);
    BST::add(root, 18);

    {
        std::list<int>* out = get_level(root, 2);
        for(auto it = out->begin(); it != out->end(); it++)
            std::cout << *it << ' ';
        std::cout << std::endl;
    }
    {
        std::list<int>* out = get_level(root, 1);
        for(auto it = out->begin(); it != out->end(); it++)
            std::cout << *it << ' ';
        std::cout << std::endl;
    }
    {
        std::list<int>* out = get_level(root, 0);
        for(auto it = out->begin(); it != out->end(); it++)
            std::cout << *it << ' ';
        std::cout << std::endl;
    }
}