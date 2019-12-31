/*
Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

Example 1:

Input:

     1
   /   \
  3     2
 / \     \
5   3     9

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:

Input:

    1
   /
  3
 / \
5   3

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:

Input:

    1
   / \
  3   2
 /
5

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
Example 4:

Input:

      1
     / \
    3   2
   /     \
  5       9
 /         \
6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).
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
    int widthOfBinaryTree(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        queue<pair<TreeNode *, uint64_t>> q;
        q.push({ root, 1 });

        int max_width = 1;
        while (!q.empty())
        {
           // auto node = q.front();
            int size = q.size();
            if (size == 1)
            {
                q.front().second = 1;
            }

            int start = q.front().second;
            int end = q.back().second;

            for (int i = 0; i < size; i++)
            {
                auto node = q.front();

                if (node.first->left != nullptr)
                    q.push({ node.first->left, 2 * node.second });

                if (node.first->right != nullptr)
                    q.push({ node.first->right, 2 * node.second + 1 });

                if (max_width < end - start + 1)
                {
                    max_width = end - start + 1;
                }
                q.pop();
            }
        }

        return max_width;
    }
};

int main()
{
    auto sol = new Solution();

    //auto root = new TreeNode(1);
    //root->left = new TreeNode(3);
    //root->right = new TreeNode(2);
    //root->left->left = new TreeNode(5);

    auto root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);

    root->right->left = new TreeNode(9);
    cout << sol->widthOfBinaryTree(root) << endl;
}
