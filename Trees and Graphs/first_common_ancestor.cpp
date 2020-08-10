#include <iostream>
#include <tuple>
#include "Tree.h"

// Update: I solved the same problem in Leetcode and submitted my solution in my other repo

/*
    The problem gets complicated that n1 can be an ancestor of n2, if that wasn't the case
    we can just return the first node that has n1 in one side and n2 in the other side
*/

// you may think we can just return the node where it has n1 in one side and n2 in the other side
// but there's a case where the tree can be structured like a linked list
BST::Node* search(BST::Node* root, BST::Node* n1, BST::Node* n2, std::tuple<bool, bool>& found)
{
    if(!root)
        return 0;
    if(root == n1)
    {
        std::cout << "here: " << root->val << std::endl;
        found = std::make_tuple(true, std::get<1>(found));
        BST::Node* l = search(root->left, n1, n2, found);
        BST::Node* r = search(root->right, n1, n2, found);
        return l ? l : r;
    }
    if(root == n2)
    {
        std::cout << "here2: " << root->val << std::endl;
        found = std::make_tuple(std::get<0>(found), true);
        BST::Node* l = search(root->left, n1, n2, found);
        BST::Node* r = search(root->right, n1, n2, found);
        return l ? l : r;
    }

    BST::Node* foundLeft = search(root->left, n1, n2, found);
    // if you have found the node, propagate it up
    if(foundLeft)
        return foundLeft;
    BST::Node* foundRight = search(root->right, n1, n2, found);
    // if you have found the node, propagate it up
    if(foundRight)
        return foundRight;

    // the current node is the first common ancestor
    if(std::get<0>(found) && std::get<1>(found))
    {
        found = std::make_tuple(false, false);
        std::cout << "hi: " << root->val << std::endl;
        return root;
    }

    return 0;
}

BST::Node* first_common_ancestor(BST::Node* root, BST::Node* n1, BST::Node* n2)
{
    std::tuple<bool, bool> t = std::make_tuple(false, false);
    BST::Node* left = search(root->left, n1, n2, t);
    // t = std::make_tuple(false, false);
    BST::Node* right = search(root->right, n1, n2, t);

    if(left || right)
        return left ? left : right;
    return root;
}

int main()
{
    BST::Node* root = 0;
    /*
                5
        3           7
    1       4           9
                            11
    */
    BST::add(root, 5);
    BST::add(root, 3);
    BST::add(root, 7);
    BST::add(root, 4);
    BST::add(root, 9);
    BST::add(root, 11);
    BST::add(root, 1);

    {
        BST::Node* out = first_common_ancestor(root, root->right->right->right, root->right->right);
        std::cout << (out ? out->val : -1) << std::endl;
    }
    {
        BST::Node* out = first_common_ancestor(root, root->left->left, root->left->right);
        std::cout << (out ? out->val : -1) << std::endl;
    }
    {
        BST::Node* out = first_common_ancestor(root, root->left->left, root->right->right->right);
        std::cout << (out ? out->val : -1) << std::endl;
    }
}