#include "Tree.h"

bool sameTree(BST::Node* s, BST::Node* t)
{
    if(!s && !t)
        return true;
    else if(!s || !t)
        return false;
    
    return s->val == t->val && sameTree(s->left, t->left) && sameTree(s->right, t->right);
}
bool checkSubtree(BST::Node* s, BST::Node* t)
{
    if(!s)
        return false;
    if(sameTree(s, t))
        return true;
    return checkSubtree(s->left, t) || checkSubtree(s->right, t);
}

int main()
{

}