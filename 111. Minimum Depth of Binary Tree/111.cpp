/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

  3
 / \
9  20
  /  \
 15   7
return its minimum depth = 2.

Accepted
*/

#include <queue>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        queue<TreeNode *> q;
        q.push(root);

        int depth = 1;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto node = q.front();

                if (node->left == nullptr && node->right == nullptr)
                {
                    return depth;
                }

                if (node->left != nullptr)
                {
                    q.push(node->left);
                }

                if (node->right != nullptr)
                {
                    q.push(node->right);
                }
                q.pop();
            }
            depth++;
        }
        return depth;
    }
};

int main()
{
    auto sol = new Solution();

    //auto root = new TreeNode(3);
    //root->left = new TreeNode(9);
    //root->right = new TreeNode(20);
    //root->right->left = new TreeNode(15);
    //root->right->right = new TreeNode(7);

    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout << sol->minDepth(root) << endl;
}