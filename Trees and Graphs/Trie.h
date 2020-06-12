#include <iostream>
#include <string>

struct Trie_Node
{
    bool end;
    char val;
    Trie_Node* children[26];
    Trie_Node() : end(false), val(0)
    {
        memset(children, 0, sizeof(children));
    }
    Trie_Node(char v, bool e) : end(e), val(v)
    {
        memset(children, 0, sizeof(children));
    }
};

class Trie
{
    void print_helper(Trie_Node* root, std::string so_far)
    {
        if(!root)
            return;
        
        if(root->end)
            std::cout << "   " << so_far << root->val << std::endl;

        for(int i = 0; i < 26; i++)
            if(root->children[i])
                print_helper(root->children[i], so_far + root->val);
    }

public:
    Trie_Node* head;
    
    Trie() : head(0) {}

    void add(std::string str)
    {
        if(!head)
        {
            head = new Trie_Node();
        }
        int i = 0;
        Trie_Node* curr = head;
        while(curr->children[str[i] - 'a'])
            curr = curr->children[str[i++] - 'a'];

        for(; i < str.size(); i++)
        {
            curr->children[str[i] - 'a'] = new Trie_Node(str[i], i == str.size()-1);
            curr = curr->children[str[i] - 'a'];
        }
    }

    void print()
    {
        std::cout << "printing:" << std::endl;
        print_helper(head, "");
    }
};