// 113. Path Sum II.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
[5,4,11,2],
[5,8,4,5]
]
*/

#include <vector>
#include <stack>
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
private:
	vector<vector<int>> result;

public:
	bool doPathSum(TreeNode* root, int sum, vector<int> &res)
	{
		if (root == nullptr)
		{
			return false;
		}

		if (root->left == nullptr && root->right == nullptr)
		{
			if (root->val == sum)
			{
				res.push_back(root->val);
				result.push_back(res);
				res.pop_back();

				return true;
			}
			else
			{
				return false;
			}
		}

		sum -= root->val;
		res.push_back(root->val);

		bool found = false;
		if (this->doPathSum(root->left, sum, res))
		{
			found = true;
		}

		if (this->doPathSum(root->right, sum, res))
		{
			found = true;
		}

		res.pop_back();

		return found;
	}

	vector<vector<int>> pathSum(TreeNode* root, int sum)
	{
		vector<int> res;
		this->doPathSum(root, sum, res);

		return result;
	}
};

int main()
{
	auto root = new TreeNode(5);
	root->left = new TreeNode(4);
	root->right = new TreeNode(8);
	root->left->left = new TreeNode(11);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);

	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);

	root->right->right->left = new TreeNode(5);
	root->right->right->right = new TreeNode(1);

	auto sol = new Solution();

	auto result = sol->pathSum(root, 22);

	for (auto row : result)
	{
		for (auto col : row)
		{
			cout << col << " ";
		}
		cout << endl;
	}
    return 0;
}


