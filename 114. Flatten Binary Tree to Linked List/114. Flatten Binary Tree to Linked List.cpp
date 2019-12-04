// 114. Flatten Binary Tree to Linked List.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

/*
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
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

class Solution
{
public:
	void flatten(TreeNode* root)
	{
		if (root == nullptr)
		{
			return;
		}

		if (root->right != nullptr)
		{
			flatten(root->right);
		}

		if (root->left != nullptr)
		{
			flatten(root->left);

			auto p = root->left;
			while (p->right != nullptr)
			{
				p = p->right;
			}
			p->right = root->right;
			root->right = root->left;
			root->left = nullptr;
		}
	}
};

int main()
{
	auto root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);

	//root->left->left = new TreeNode(3);
	//root->left->right = new TreeNode(4);
	//root->right->right = new TreeNode(6);
	
	auto sol = new Solution();
	sol->flatten(root);

	auto p = root;
	while (p != nullptr)
	{
		cout << p->val << " ";

		if (p->left == nullptr)
		{
			cout << "null ";
		}
		else
		{
			cout << "xxxxxxx";
		}
		//else if (p->right == nullptr)
		//{
		//	cout << "null ";
		//}
		
		p = p->right;
	}

    return 0;
}

