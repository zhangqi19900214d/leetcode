/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
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
			return ;
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


	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
	{
		if (preorder.size() != inorder.size() || preorder.size() == 0)
		{
			return nullptr;
		}

		if (preorder.size() == 1)
		{
			return new TreeNode(preorder[0]);
		}

		TreeNode *root = new TreeNode(preorder[0]);

		int key = preorder[0];
		vector<int> preorder_left, inorder_left;
		vector<int> preorder_right, inorder_right;

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
			preorder_left.push_back(preorder[i+1]);
			inorder_left.push_back(inorder[i]);
		}

		for (int i = index + 1; i < preorder.size(); i++)
		{
			preorder_right.push_back(preorder[i]);
			inorder_right.push_back(inorder[i]);
		}

		root->left = buildTree(preorder_left, inorder_left);
		root->right = buildTree(preorder_right, inorder_right);

		return root;
	}
};

int main()
{
	auto sol = new Solution();
	sol->print(sol->buildTree(vector<int>{1,2,3}, vector<int>{3,2,1}));
	//sol->print(sol->buildTree(vector<int>{3, 9, 20, 15, 7}, vector<int>{9, 3, 15, 20, 7}));
}