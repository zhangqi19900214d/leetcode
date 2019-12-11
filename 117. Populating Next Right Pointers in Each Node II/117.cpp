/*
Given a binary tree

struct Node {
int val;
Node *left;
Node *right;
Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.



Follow up:

You may only use constant extra space.
Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.


Example 1:



Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.


Constraints:

The number of nodes in the given tree is less than 6000.
-100 <= node.val <= 100
*/

#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;

class Node
{
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
	void printWithLevel(Node *root)
	{
		if (root == nullptr)
		{
			return;
		}

		queue<Node *> q, nextLevel;
		q.push(root);

		while (!q.empty())
		{
			Node *node = q.front();
			q.pop();

			cout << node->val << " ";
			cout << (node->next == nullptr ? "# " : "");

			if (node->left) nextLevel.push(node->left);
			if (node->right) nextLevel.push(node->right);

			if (q.empty())
			{
				while (!nextLevel.empty())
				{
					auto n = nextLevel.front();
					nextLevel.pop();
					q.push(n);
				}
				cout << endl;
			}
		}
	}

	Node* connect(Node* root)
	{
		if (root == nullptr)
		{
			return root;
		}

		queue<Node *> q, nextLevel;
		q.push(root);

		while (!q.empty())
		{
			Node *node = q.front();
			q.pop();

			if (node->left) nextLevel.push(node->left);
			if (node->right) nextLevel.push(node->right);

			if (q.empty())
			{
				node->next = nullptr;
				Node *pre = nullptr;

				while (!nextLevel.empty())
				{
					auto n = nextLevel.front();
					nextLevel.pop();
					if (pre != nullptr)
					{
						pre->next = n;
						pre = pre->next;
					}
					else
					{
						pre = n;
					}
					q.push(n);
				}
			}
		}
		return root;
	}
};

int main()
{
	auto sol = new Solution();

	Node *root = new Node(1);

	root->left = new Node(2);
	root->right = new Node(3);

	root->left->left = new Node(4);
	root->left->right = new Node(5);

	//root->right->left = new Node(6);
	root->right->right = new Node(7);

	sol->printWithLevel(root);

	root = sol->connect(root);

	sol->printWithLevel(root);
}
