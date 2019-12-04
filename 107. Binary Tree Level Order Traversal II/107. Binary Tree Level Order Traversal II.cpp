// 107. Binary Tree Level Order Traversal II.cpp : 定义控制台应用程序的入口点。
//

/*Given a binary tree, return the bottom - up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example :
Given binary tree[3, 9, 20, null, null, 15, 7],
  3
 / \
9  20
  / \
 15  7
return its bottom - up level order traversal as :
[
	[15, 7],
	[9, 20],
	[3]
]
*/

#include "stdafx.h"

#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrderBottom(TreeNode* root)
	{
		vector<vector<int>> result;

		if (root == nullptr)
		{
			return result;
		}

		std::queue<TreeNode *> vist;
		std::queue<TreeNode *> tmp;

		vist.push(root);
		vector<int> layer;

		while (!vist.empty())
		{
			TreeNode *node = vist.front();
			vist.pop();
			layer.push_back(node->val);

			if (node->left != nullptr)
			{
				tmp.push(node->left);
			}
			if (node->right != nullptr)
			{
				tmp.push(node->right);
			}

			if (vist.empty())
			{
				result.insert(result.begin(), layer);
				layer.clear();

				while (!tmp.empty())
				{
					auto t = tmp.front();
					vist.push(t);
					tmp.pop();
				}
			}
		}

		return result;
    }
};

int main()
{
	TreeNode * root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	auto sol = new Solution();
	auto result = sol->levelOrderBottom(root);

	for (int i = 0; i < result.size(); ++i)
	{
		for (int j = 0; j < result[i].size(); ++j)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}

    return 0;
}

