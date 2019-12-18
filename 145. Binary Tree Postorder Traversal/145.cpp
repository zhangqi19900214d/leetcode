/*
Given a binary tree, return the postorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
 1
  \
  2
 /
3

Output: [3,2,1]
Follow up: Recursive solution is trivial, could you do it iteratively?
*/
#include <iostream>
#include <stack>
#include <vector>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:

    void print(vector<int> &res)
    {
        for (auto iter : res)
        {
            cout << iter << " ";
        }
        cout << endl;
    }

    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> result;
        if (root == nullptr)
        {
            return result;
        }

        stack<TreeNode *>stack;

        for (auto p = root; p != nullptr; p = p->left)
        {
            stack.push(p);
        }

        TreeNode *r = root;
        map<TreeNode*, bool> visit;

        while (!stack.empty())
        {
            auto node = stack.top();

            if (node->right != nullptr && !visit[node->right])
            {
                for (auto p = node->right; p != nullptr; p = p->left)
                {
                    stack.push(p);
                }
                r = node;
                continue;
            }
            stack.pop();
            visit[node] = true;
           // cout << node->val << endl;
            result.push_back(node->val);
        }

        return result;
    }
};

int main()
{
    auto sol = new Solution();
    auto root = new TreeNode(1);

    root->left = new TreeNode(4);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    sol->print(sol->postorderTraversal(root));
}