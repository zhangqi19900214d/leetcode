// 040. Combination Sum II.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
[1, 7],
[1, 2, 5],
[2, 6],
[1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
[1,2,2],
[5]
]*/

#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
	void dfs(int start, int sum, int target, vector<int> &ans, const vector<int> &candidates, set<vector<int>> &result)
	{
		if (sum == target)
		{
			result.insert(ans);
			return;
		}
		else if (sum > target)
		{
			return ;
		}
		else
		{
			for (int i = start; i < candidates.size(); i++)
			{
				ans.push_back(candidates[i]);
				dfs(i + 1, sum + candidates[i], target, ans, candidates, result);
				ans.pop_back();
			}
		}
	}

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
	{
		set<vector<int>> result;
		vector<int> ans;

		sort(candidates.begin(), candidates.end());

		dfs(0, 0, target, ans, candidates, result);

		vector<vector<int>> ret;
		for (auto item : result)
		{
			ret.push_back(item);
		}

		return ret;
	}
};

int main()
{
	vector<int> input{ 10,1,2,7,6,1,5 };
	auto sol = new Solution();
	auto result = sol->combinationSum2(input, 8);

	for (auto item : result)
	{
		for (auto k : item)
		{
			cout << k << " ";
		}
		cout << endl;
	}

    return 0;
}

