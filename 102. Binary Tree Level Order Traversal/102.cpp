/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
   3
  / \
 9  20
 /  \
15   7
return its level order traversal as:
[
[3],
[9,20],
[15,7]
]
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
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		vector<vector<int>> result;
		vector<int> ans;

		if (root == nullptr)
		{
			return result;
		}

		queue<TreeNode *> q;
		queue<TreeNode *> tmp;

		q.push(root);
		while (!q.empty())
		{
			auto node = q.front();
			q.pop();

			ans.push_back(node->val);

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
				while (!tmp.empty())
				{
					q.push(tmp.front());
					tmp.pop();
				}

				result.push_back(ans);
				ans.clear();
			}
		}
		return result;
	}
};

int main()
{
	auto sol = new Solution();
}