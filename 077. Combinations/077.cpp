/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
[2,4],
[3,4],
[2,3],
[1,2],
[1,3],
[1,4],
]
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:

	void dfs(int start, vector<int> &ans, vector<vector<int>> &result, int n, int k)
	{
		if (ans.size() == k)
		{
			result.push_back(ans);
			return;
		}
		if (ans.size() > k)
		{
			return;
		}

		if (ans.size() < k)
		{
			for (int i = start; i <= n; i++)
			{
				ans.push_back(i);
				dfs(i + 1, ans, result, n, k);
				ans.pop_back();
			}
		}
	}
	vector<vector<int>> combine(int n, int k)
	{
		vector<vector<int>> result;
		vector<int> ans;

		dfs(1, ans, result, n, k);

		return result;
	}
};

int main()
{
	auto sol = new Solution();
	auto res = sol->combine(4, 3);

	for (auto item : res)
	{
		for (auto k : item)
		{
			cout << k << " ";
		}
		cout << endl;
	}
}