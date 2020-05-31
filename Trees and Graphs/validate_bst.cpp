#include <iostream>
#include "Tree.h"

bool validate_bst(BST::Node* root)
{
    if(!root)
        return true;
    int right = root->right ? root->right->val : root->val + 1;
    int left = root->left ? root->left->val : root->val;
    if(root->val < left || root->val >= right)
        return false;
    return validate_bst(root->left) && validate_bst(root->right);
}

int main()
{
    BST::Node* root = 0;

    BST::add(root, 5);
    BST::add(root, 3);
    BST::add(root, 7);
    std::cout << validate_bst(root) << std::endl;

    root->left->right = new BST::Node(1);
    std::cout << validate_bst(root) << std::endl;

    root->left->right = new BST::Node(4);
    std::cout << validate_bst(root) << std::endl;

    root->right->right = new BST::Node(1);
    std::cout << validate_bst(root) << std::endl;

    root->right->right = new BST::Node(10);
    std::cout << validate_bst(root) << std::endl;
}