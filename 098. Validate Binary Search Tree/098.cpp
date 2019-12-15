/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


Example 1:

2
/ \
1   3

Input: [2,1,3]
Output: true
Example 2:

5
/ \
1   4
/ \
3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
*/

#include <iostream>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

	bool check(TreeNode *node, TreeNode *min, TreeNode *max)
	{
		if (node == nullptr)
		{
			return true;
		}

		if ((max != nullptr && node->val >= max->val) || (min != nullptr && node->val <= min->val))
		{
			return false;
		}

		return check(node->left, min, node) && check(node->right, node, max);
	}

	bool isValidBST(TreeNode* root)
	{
		if (nullptr == root)
		{
			return true;
		}

		return this->check(root->left, nullptr, root) && this->check(root->right, root, nullptr);
	}
};

int main()
{
	auto sol = new Solution();

	auto root1 = new TreeNode(5);

	root1->left = new TreeNode(1);
	root1->right = new TreeNode(4);

	root1->right->left = new TreeNode(3);
	root1->right->right = new TreeNode(6);

	//cout << sol->isValidBST(root1) << endl;

	auto root2 = new TreeNode(10);

	root2->left = new TreeNode(5);
	root2->right = new TreeNode(15);

	root2->right->left = new TreeNode(6);
	root2->right->right = new TreeNode(20);

	//cout << sol->isValidBST(root2) << endl;

	auto root3 = new TreeNode(3);
	root3->left = new TreeNode(1);

	root3->left->left = new TreeNode(0);
	root3->left->right = new TreeNode(2);

	root3->left->right->left = new TreeNode(3);

	cout << sol->isValidBST(root3) << endl;
}