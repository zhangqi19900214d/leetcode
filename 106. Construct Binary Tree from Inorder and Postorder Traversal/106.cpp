/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

   3
  / \
 9  20
 /  \
15   7

*/


#include <vector>
#include <queue>
#include <map>
#include <algorithm>
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
	void print(TreeNode* root)
	{
		if (root == nullptr)
		{
			return;
		}

		queue<TreeNode *> q;
		queue<TreeNode *> tmp;

		q.push(root);
		while (!q.empty())
		{
			auto node = q.front();
			q.pop();

			cout << node->val << " ";

			node->left != nullptr ? tmp.push(node->left) : "";
			node->right != nullptr ? tmp.push(node->right) : "";

			if (q.empty())
			{
				while (!tmp.empty())
				{
					q.push(tmp.front());
					tmp.pop();
				}
				cout << endl;
			}
		}
	}

	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
	{
		if (postorder.size() != inorder.size() || postorder.size() == 0)
		{
			return nullptr;
		}

		int key = postorder[postorder.size() - 1];

		TreeNode *root = new TreeNode(key);

		vector<int> postorder_left, inorder_left;
		vector<int> postorder_right, inorder_right;

		int index = 0;
		for (int i = 0; i < inorder.size(); i++)
		{
			if (inorder[i] == key)
			{
				break;
			}
			index++;
		}

		for (int i = 0; i < index; i++)
		{
			postorder_left.push_back(postorder[i]);
			inorder_left.push_back(inorder[i]);
		}

 		for (int i = index+1; i < postorder.size(); i++)
		{
			postorder_right.push_back(postorder[i-1]);
			inorder_right.push_back(inorder[i]);
		}

		root->left = buildTree(inorder_left, postorder_left);
		root->right = buildTree(inorder_right, postorder_right);

		return root;
	}
};

int main()
{
	auto sol = new Solution();
	sol->print(sol->buildTree(vector<int>{1}, vector<int>{1}));
	sol->print(sol->buildTree(vector<int>{9, 3, 15, 20, 7}, vector<int>{ 9, 15, 7, 20, 3 }));
}