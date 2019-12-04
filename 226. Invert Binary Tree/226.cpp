/*
Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:

Google: 90% of our engineers use the software you wrote (Homebrew), but you can¡¯t invert a binary tree on a whiteboard so f*** off.
*/

#include <stdio.h>
#include <iostream>

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
	TreeNode* invertTree(TreeNode* root) 
	{
		if (root == nullptr)
		{
			return root;
		}
		else if (root->left == nullptr)
		{
			root->left = this->invertTree(root->right);
			root->right = nullptr;
			return root;
		}
		else if (root->right == nullptr)
		{
			root->right = this->invertTree(root->left);
			root->left = nullptr;
			return root;
		}

		auto left = this->invertTree(root->left);
		auto right = this->invertTree(root->right);

		root->left = right;
		root->right = left;

		return root;
	}
};

int main()
{
	auto sol = new Solution();

	TreeNode *root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(7);

	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);

	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(9);

	cout << root->val << endl;
	cout << root->left->left->val << endl;
	cout << root->right->right->val << endl;

	root = sol->invertTree(root);
	
	cout << "xxxxxxxxxx" << endl;

	cout << root->val << endl;
	cout << root->left->left->val << endl;
	cout << root->right->right->val << endl;
}