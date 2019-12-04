/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
[1,1,2],
[1,2,1],
[2,1,1]
]
*/

#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
	void dfs(int start, const vector<int>& nums, vector<int> &visit, vector<int> &ans, set<vector<int>> &result)
	{
		if (ans.size() == nums.size())
		{
			result.insert(ans);
			return;
		}
		else if (ans.size() < nums.size())
		{
			for (int i = 0; i < nums.size(); ++i)
			{
				if (visit[i] == 0)
				{
					visit[i] = 1;
					ans.push_back(nums[i]);

					dfs(i + 1, nums, visit, ans, result);
					visit[i] = 0;
					ans.pop_back();
				}
			}
		}
	}
	//[1, 1, 2]

	vector<vector<int>> permuteUnique(vector<int>& nums) 
	{
		set<vector<int>> result;
		vector<int> visit(nums.size());
		vector<int> ans;

		dfs(0, nums, visit, ans, result);

		vector<vector<int>> ret;
		for (auto res : result)
		{
			ret.push_back(res);
		}
		return ret;
	}
};

int main()
{
	auto sol = new Solution();
	vector<int> nums{1,1,2};
	auto res = sol->permuteUnique(nums);

	cout << res.size() << endl;
	for (auto item : res)
	{
		for (auto x : item)
		{
			cout << x << " ";
		}
		cout << endl;
	}
}