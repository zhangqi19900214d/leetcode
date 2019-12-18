/*
Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
1
 \
  2
 /
3

Output: [1,2,3]
Follow up: Recursive solution is trivial, could you do it iteratively?
*/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

	void print(vector<int> &res)
	{
		for (auto iter : res)
		{
			cout << iter << " ";
		}
		cout << endl;
	}

	vector<int> preorderTraversal(TreeNode* root)
	{
		vector<int> result;
		if (root == nullptr)
		{
			return result;
		}

		stack<TreeNode *>stack;
		stack.push(root);
		
        while (!stack.empty())
        {
            auto node = stack.top();
            stack.pop();

            result.push_back(node->val);
            
            if (node->right != nullptr)
            {
                stack.push(node->right);
            }
            if (node->left != nullptr)
            {
                stack.push(node->left);
            }
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

    sol->print(sol->preorderTraversal(root));
}