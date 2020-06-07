#include <iostream>
#include <time.h>
#include "Tree.h"

int size(BST::Node* root)
{
    if(!root)
        return 0;
    return size(root->left) + size(root->right) + 1;
}

BST::Node* helper(BST::Node* root, int rand, int& curr)
{
    if(!root)
        return 0;
    if(curr == rand)
        return root;
    curr += 1;
    BST::Node* l = helper(root->left, rand, curr);
    return l ? l : helper(root->right, rand, curr);
}

BST::Node* getRandomNode(BST::Node* root)
{
    srand(time(0));
    int s = size(root);
    int curr = 0;
    return helper(root, rand() % s, curr);
}

int main()
{
    BST::Node* root = 0;
    BST::add(root, 10);
    BST::add(root, 5);
    BST::add(root, 25);
    BST::add(root, 3);
    BST::add(root, 4);
    BST::add(root, 15);
    BST::add(root, 20);
    BST::add(root, 30);

    BST::Node* r = getRandomNode(root);
    std::cout << (r ? r->val : -1) << std::endl;
}
