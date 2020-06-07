#include <iostream>
#include <set>
#include<vector>
#include "Tree.h"
using namespace std;

/*
    for generating all permutations of a level in a BST
    we get the level of BST in an array and pass it here
*/
void permute_helper(vector<vector<int>>* out, vector<int> arr, int start, int end)
{
    if(start >= end)
    {
        out->push_back(arr);
        return;
    }
    for(int i = start; i < end; i++)
    {
        std::swap(arr[start], arr[i]);
        permute_helper(out, arr, start+1, end);
    }
}

vector<vector<int>> permutations(vector<int> arr)
{
    vector<vector<int>> out;
    permute_helper(&out, arr, 0, arr.size());
    return out;
}

/*
    for getting a level in a BST, we then generate all permutation of it
*/
void get_level_helper(vector<int>* out, int depth, int curr, BST::Node* root)
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
vector<int>* get_level(BST::Node* root, int depth)
{
    vector<int>* out = new vector<int>();
    get_level_helper(out, depth, 0, root);
    return out;
}

void print(const vector<vector<int>>& out)
{
    for(auto vec : out)
    {
        for(int num : vec)
            cout << num << " ";
        cout << endl;
    }
}

void print(const vector<int>& vec)
{
    for(int num : vec)
        cout << num << " ";
    cout << endl;
}

vector<int> operator+(const vector<int>& v, const vector<int>& v2)
{
    vector<int> out;
    out.reserve(v.size() + v2.size());
    for(int i : v)
        out.push_back(i);
    for(int i : v2)
        out.push_back(i);
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

    vector<vector<int>> out;

    int depth = BST::get_height(root);

    for(int i = 0; i < depth; i++)
    {
        vector<int>* level = get_level(root, i);
        vector<vector<int>> perm = permutations(*level);

        vector<vector<int>> new_out;

        if(!out.size())
            for(auto v : perm)
                new_out.push_back(v);
        else
            for(vector<int> v : out)
                for(vector<int> vv : perm)
                    new_out.push_back(v + vv);

        out = new_out;
    }

    print(out);
}
