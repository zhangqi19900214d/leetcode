// 129. Sum Root to Leaf Numbers.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

Note: A leaf is a node with no children.

Example:

Input: [1,2,3]
  1
 / \
2   3
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.
Example 2:

Input: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.
*/

#include <vector>
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

	bool vist(TreeNode* root, vector<int> &res)
	{
		if (root == nullptr)
		{
			return true;
		}


		if (root->left == nullptr && root->right == nullptr)
		{
			//result.push_back(res);
			return true;
		}
		res.push_back(root->val);

		if (root->left != nullptr)
		{
			if (this->vist(root->left, res))
			{
				res.push_back(root->left->val);
				result.push_back(res);
				res.pop_back();
			}
		}
		
		if (root->right != nullptr)
		{
			if (this->vist(root->right, res))
			{
				res.push_back(root->right->val);
				result.push_back(res);
				res.pop_back();
			}
		}

		res.pop_back();

		return false;
	}

	int sumNumbers(TreeNode* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		if (root->left == nullptr && root->right == nullptr)
		{
			return root->val;
		}
		vector<int> res;
		this->vist(root, res);

		int sum = 0;

		for (int i = 0; i < result.size(); ++i)
		{
			auto item = result[i];

			int n = 0;
			for (auto iter : item)
			{
				n *= 10;
				n += iter;
				//cout << iter << " ";
			}
			//cout << n << endl;
			//cout << endl;
			sum += n;
		}

		return sum;
	}
};


int main()
{
	auto root = new TreeNode(4);
	root->left = new TreeNode(9);
	root->right = new TreeNode(0);
	
	root->left->left = new TreeNode(5);
	root->left->right = new TreeNode(1);

	auto sol = new Solution();
	cout << sol->sumNumbers(root) << endl;

    return 0;
}

