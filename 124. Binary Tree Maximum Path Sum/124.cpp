/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

  1
 / \
2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

 -10
  / \
 9  20
 /  \
15   7

Output: 42
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	int maxPath = -1000000;
	int nodePath(TreeNode* node)
	{
		if (node == nullptr)
		{
			return 0;
		}
		int l = this->maxPathSum(node->left);
		int r = this->maxPathSum(node->right);

		int ret = max(max(l, r), 0);

		ret = max(ret, ret + node->val);

		/*int m = this->maxPathSum(node);
		int ret = max(m, 0) + node->val;*/

		cout << node->val << " " << ret << endl;

		return ret;
	}

	int maxPathSum(TreeNode* root)
	{
		if (root == nullptr)
		{
			return 0;
		}

		int l = this->nodePath(root->left);
		int r = this->nodePath(root->right);

		int ml = l + root->val;
		int mr = r + root->val;
		int mt = l + r;

		int ret = max(max(max(l, r), l + r), 0);

		ret = max(ret, ret + root->val);

		return ret;
	}
};


int main()
{
	auto sol = new Solution();

	//auto root = new TreeNode(1);
	//root->left = new TreeNode(2);
	//root->right = new TreeNode(3);

	auto root = new TreeNode(-10);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);

	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	cout << sol->maxPathSum(root) << endl;
} 