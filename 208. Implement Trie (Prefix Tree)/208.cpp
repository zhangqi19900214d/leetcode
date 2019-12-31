/*
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/

#include <stack>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

#define MAX_CHILD ('z'-'a'+1)
struct TireNode
{
    char value;
    int  end_cnt;
    bool end_word;
    vector<TireNode *> child{ MAX_CHILD };

    TireNode(char v = '#')
    {
        value = v;
        end_cnt = 0;
        end_word = false;
    }
};

class Trie
{
public:
    /** Initialize your data structure here. */
    Trie()
    {
        _root = new_node('#');
    }

    ~Trie()
    {
        stack<TireNode *> st;
        st.push(_root);

        while (!st.empty())
        {
            TireNode *node = st.top();

            if (!has_child(node))
            {
                st.pop();
                free_node(node);
            }

            for (int i = 0; node != nullptr && i < node->child.size(); i++)
            {
                if (node->child[i] != nullptr)
                {
                    st.push(node->child[i]);
                    node->child[i] = nullptr;
                }
            }
        }
    }
    void free_node(TireNode *&node)
    {
        delete node;
        node = nullptr;
    }

    TireNode *new_node(char v, TireNode *parent = nullptr)
    {
        TireNode *p = new TireNode(v);

        return p;
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TireNode *p = _root;
        for (int i = 0; i < word.size(); i++)
        {
            char ch = word.at(i);
            if (p->child[ch-'a'] == nullptr)
            {
                p->child[ch-'a'] = new_node(ch, p);
            }

            if (i + 1 == word.size())
            {
                p->child[ch - 'a']->end_cnt += 1;
                p->child[ch - 'a']->end_word = true;
            }
            p = p->child[ch - 'a'];
        }
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TireNode *p = _root;
        for (int i = 0; i < word.size(); i++)
        {
            char ch = word.at(i);

            if (p->child[ch - 'a'] != nullptr)
            {
                p = p->child[ch - 'a'];
            }
            else
            {
                return false;
            }
        }

        return p->end_word;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TireNode *p = _root;
        for (int i = 0; i < prefix.size(); i++)
        {
            char ch = prefix.at(i);

            if (p->child[ch - 'a'] != nullptr)
            {
                p = p->child[ch - 'a'];
            }
            else
            {
                return false;
            }
        }

        return true;
    }

    bool has_child(TireNode *node)
    {
        for (int i = 0; i < node->child.size(); i++)
        {
            if (node->child[i] != nullptr)
            {
                return true;
            }
        }

        return false;
    }
private:
    TireNode *_root;
};

int main()
{
    Trie* obj = new Trie();
    obj->insert("word");
    obj->insert("wand");
    cout << obj->search("word") << endl;
    cout << obj->startsWith("wa") << endl;
}