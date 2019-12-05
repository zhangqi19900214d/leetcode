#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
[2],
[1],
[1,2,2],
[2,2],
[1,2],
[]
]
*/

class Solution {
public:

	void dfs(int start, vector<int> &ans, set<vector<int>> &result, const vector<int> &nums)
	{
		if (ans.size() <= nums.size())
		{
			result.insert(ans);
		}
		
		for (int i = start; i < nums.size(); i++)
		{
			ans.push_back(nums[i]);
			dfs(i + 1, ans, result, nums);
			ans.pop_back();
		}
	}

	vector<vector<int>> subsetsWithDup(vector<int>& nums)
	{
		set<vector<int>> result;
		vector<int> ans;

		sort(nums.begin(), nums.end());
		dfs(0, ans, result, nums);

		vector<vector<int>> res;

		for (auto &iter : result)
		{
			res.push_back(iter);
		}

		return res;
	}
};

int main()
{
	auto sol = new Solution();
	vector<int> nums{ 4,4,4,4,1,4 };

	auto res = sol->subsetsWithDup(nums);
	for (auto item : res)
	{
		for (auto n : item)
		{
			cout << n << " ";
		}
		cout << endl;
	}

	cout << res.size() << endl;
}