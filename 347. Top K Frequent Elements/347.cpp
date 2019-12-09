/*
Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ¡Ü k ¡Ü number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
	struct node_t
	{
		node_t(int f = 0, int v = 0)
		{
			value = v;
			freq = f;
		}

		int value;
		int freq;
	};

	void insertNode(vector<node_t> &tree, int n)
	{
		
	}

	void createHeapTree(vector<node_t> &tree, int n)
	{
		if (tree.empty())
		{
			tree.push_back(node_t(1, n));
			return;
		}

		//insertNode(tree, n);
	}

	vector<int> topKFrequent(vector<int>& nums, int k)
	{
		vector<node_t> tree;

		for (int i = 0; i < nums.size(); i++)
		{
			createHeapTree(tree, nums[i]);
		}

		vector<int> result;
		return result;
	}
};

int main()
{
	auto sol = new Solution();
	auto result = sol->topKFrequent(vector<int>{1, 1, 1, 2, 2, 3}, 2);

	for (auto res : result)
	{
		cout << res << endl;
	}
}