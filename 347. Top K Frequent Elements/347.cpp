/*
Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ¡Ü k ¡Ü number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

#include <stack>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_CHILD 128
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

struct TireTree
{
    TireNode *_root;
    TireTree()
    {
        _root = new TireNode();
    }

    ~TireTree()
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
        //cout << "free " << node->value << endl;

        delete node;
        node = nullptr;
    }

    TireNode *new_node(char v, TireNode *parent = nullptr)
    {
        TireNode *p = new TireNode(v);

        return p;
    }

    void insert(int value)
    {
        insert(to_string(value));
    }

    void insert(const string &value)
    {
        TireNode *p = _root;
        for (int i = 0; i < value.size(); i++)
        {
            char ch = value.at(i);
            if (p->child[ch] == nullptr)
            {
                p->child[ch] = new_node(ch, p);
            }

            if (i + 1 == value.size())
            {
                p->child[ch]->end_cnt += 1;
                p->child[ch]->end_word = true;
            }
            p = p->child[ch];
        }
    }

    bool search(int value)
    {
        return search(to_string(value));
    }

    bool search(const string &value)
    {
        TireNode *p = _root;
        for (int i = 0; i < value.size(); i++)
        {
            char ch = value.at(i);

            if (p->child[ch] != nullptr)
            {
                p = p->child[ch];
            }
            else
            {
                return false;
            }
        }

        return p->end_word;
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

    void check_count(const string &prefix, TireNode *node, vector<pair<string, int>> &result)
    {
        if (node == nullptr)
        {
            return;
        }

        if (!has_child(node))
        {
            result.emplace_back(make_pair(prefix + node->value, node->end_cnt));
        }
        else
        {
            for (int i = 0; i < node->child.size(); i++)
            {
                if (node->child[i] != nullptr)
                {
                    check_count(prefix + node->value, node->child[i], result);
                }
            }
            if (node->end_word)
            {
                result.emplace_back(make_pair(prefix + node->value, node->end_cnt));
            }
        }
    }

    void check_count(vector<pair<string, int>> &result)
    {
        check_count("", _root, result);

        //for (auto item : result)
        //{
        //    cout << item.first << " : " << item.second << endl;
        //}
    }
};

class Solution
{
public:
	vector<int> topKFrequent(vector<int>& nums, int k)
	{
        TireTree tree;
        for (int i = 0; i < nums.size(); i++)
        {
            tree.insert(nums[i]);
        }

        vector<pair<string, int>> result;
        tree.check_count(result);

        std::sort(result.begin(), result.end(), [](const pair<string, int> &a, const pair<string, int> &b) {
            return a.second > b.second;
        });

        vector<int> ret;

        for (int i = 0; k-- > 0 && i < result.size(); i++)
        {
            ret.emplace_back(atoi(result[i].first.substr(1, -1).c_str()));
        }

		return ret;
	}
};

int main()
{
	auto sol = new Solution();
	//auto result = sol->topKFrequent(vector<int>{1, 1, 1, 2, 2, 3}, 2);
    auto result = sol->topKFrequent(vector<int>{1, 2, 3, 1, 2, 4, 5, 5, 6, 7, 7, 8, 2, 3, 1, 1, 1, 10, 11, 5, 6, 2, 4, 7, 8, 5, 6}, 10);

	for (auto res : result)
	{
		cout << res << " ";
	}
}