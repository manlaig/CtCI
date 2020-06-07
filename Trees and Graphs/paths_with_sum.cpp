#include <iostream>
#include "Tree.h"

int numPaths(BST::Node* root, int sum)
{
    if(!root || sum < 0)
        return 0;
    return numPaths(root->left, sum - root->val)
            + numPaths(root->right, sum - root->val)
            + (sum - root->val == 0 ? 1 : 0);
}

int main()
{
    /*
                        10
                5               15
            0       10      12      20
    */
    BST::Node* root = 0;
    BST::add(root, 10);
    BST::add(root, 5);
    BST::add(root, 15);
    BST::add(root, 20);
    BST::add(root, 0);
    BST::add(root, 10);
    BST::add(root, 12);

    std::cout << numPaths(root, 15) << std::endl;
    std::cout << numPaths(root, 25) << std::endl;
    std::cout << numPaths(root, 0) << std::endl;
    std::cout << numPaths(root, 22) << std::endl;
    std::cout << numPaths(root, 37) << std::endl;
}