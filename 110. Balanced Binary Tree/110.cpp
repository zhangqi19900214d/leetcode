/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.



Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
 / \
15  7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

      1
     / \
    2   2
   / \
  3   3
 / \
4   4
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

	int getDepth(TreeNode *root)
	{
		if (root == nullptr)
		{
			return 0;
		}

		return std::max(getDepth(root->left), getDepth(root->right)) + 1;
	}

	bool isBalanced(TreeNode* root)
	{
		if (root == nullptr)
		{
			return true;
		}

		if (std::abs(getDepth(root->right) - getDepth(root->left)) <= 1)
		{
			return isBalanced(root->left) && isBalanced(root->right);
		}
		else
		{
			return false;
		}
	}
};

int main()
{
	auto root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);

	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	auto sol = new Solution();
	cout << sol->isBalanced(root) << endl;
}