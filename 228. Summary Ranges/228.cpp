/*
Given a sorted integer array without duplicates, return the summary of its ranges.

Example 1:

Input:  [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
Example 2:

Input:  [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
	void print(vector<string> &result)
	{
		for (auto &iter : result)
		{
			cout << iter << " ";
		}
		cout << endl;
	}

	string format(vector<int> &ans)
	{
		if (ans.size() == 1)
		{
			return to_string(ans[0]);
		}
		else if (ans.size() > 1)
		{
			return to_string(*ans.begin()) + "->" + to_string(*ans.rbegin());
		}
		else
		{
			return "";
		}
	}

	void dfs(int index, vector<int> &ans, vector<bool> &visit, vector<string> &result, const vector<int>& nums)
	{
		if (index >= nums.size() || visit[index])
		{
			return ;
		}

		if (!ans.empty() && nums[index] != *ans.rbegin() + 1)
		{
			return;
		}
		else
		{
			ans.push_back(nums[index]);
			visit[index] = true;
			dfs(index + 1, ans, visit, result, nums);
		}
	}

	vector<string> summaryRanges(vector<int>& nums)
	{
		vector<string> result;
		vector<bool> visit(nums.size(), false);

		for (int i = 0; i < nums.size(); i++)
		{
			vector<int> ans;
			dfs(i, ans, visit, result, nums);
			if (ans.size() > 0)
			{
				result.push_back(this->format(ans));
			}
		}

		return result;
	}
};

int main()
{
	auto sol = new Solution();
	sol->print(sol->summaryRanges(vector<int>{7}));
	sol->print(sol->summaryRanges(vector<int>{0, 1, 2, 4, 5, 7}));
	sol->print(sol->summaryRanges(vector<int>{0, 2, 3, 4, 6, 8, 9}));
}
