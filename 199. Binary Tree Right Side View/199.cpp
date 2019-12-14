/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
*/

#include <vector>
#include <queue>
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
	vector<int> rightSideView(TreeNode* root)
	{
		if (root == nullptr)
		{
			return vector<int>{};
		}

		vector<int> result;
		queue<TreeNode *> q;
		queue<TreeNode *> tmp;

		q.push(root);

		while (!q.empty())
		{
			auto node = q.front();
			q.pop();

			if (node->left != nullptr)
			{
				tmp.push(node->left);
			}

			if (node->right != nullptr)
			{
				tmp.push(node->right);
			}

			if (q.empty())
			{
				result.push_back(node->val);

				while (!tmp.empty())
				{
					q.push(tmp.front());
					tmp.pop();
				}
			}
		}

		return result;
	}
};

int main()
{
	auto sol = new Solution();
	auto root = new TreeNode(1);

	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	
	root->left->right = new TreeNode(5);
	root->right-> right = new TreeNode(4);

	auto res = sol->rightSideView(nullptr);

	for (auto iter : res)
	{
		cout << iter << " ";
	}
}