/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
[3],
[1],
[2],
[1,2,3],
[1,3],
[2,3],
[1,2],
[]
]
*/

#include<vector>
#include <iostream>

using namespace std;

class Solution
{
public:
	void dfs(int start, vector<int> &ans, vector<vector<int>> &result, const vector<int>  &nums)
	{
		if (!ans.empty())
		{
			result.push_back(ans);
		}

		if (ans.size() == nums.size())
		{
			return;
		}

		for (int i = start; i < nums.size(); i++)
		{
			ans.push_back(nums[i]);
			dfs(i + 1, ans, result, nums);
			ans.pop_back();
		}
	}

	vector<vector<int>> subsets(vector<int>& nums)
	{
		vector<vector<int>> result;
		vector<int> ans;

		result.push_back(vector<int>{});

		dfs(0, ans, result, nums);

		return result;
	}
};

int main()
{
	vector<int> nums{ 1, 2, 3 };
	auto sol = new Solution();

	auto res = sol->subsets(nums);

	for (auto item : res)
	{
		for (auto k : item)
		{
			cout << k << " ";
		}
		cout << endl;
	}
}