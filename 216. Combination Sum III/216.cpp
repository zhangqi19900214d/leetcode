/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
	void print(vector<vector<int>> &result)
	{
		for (auto iter : result)
		{
			for (auto v : iter)
			{
				cout << v << " ";
			}
			cout << endl;
		}
	}
	void dfs(int index, vector<int> &ans, int sum, vector<bool> &visit, vector<vector<int>> &result, int k, int n)
	{
		if (ans.size() == k)
		{
			if (sum == n)
			{
				result.push_back(ans);
			}
			return;
		}

		for (int i = index; i < 10; i++)
		{
			if (!visit[i] && sum < n)
			{
				visit[i] = true;
				ans.push_back(i);
				dfs(i + 1, ans, sum + i, visit, result, k, n);
				visit[i] = false;
				ans.pop_back();
			}
		}
	}

	vector<vector<int>> combinationSum3(int k, int n)
	{
		vector<vector<int>> result;
		vector<bool> visit(10, false);
		vector<int> ans;

		dfs(1, ans, 0, visit, result, k, n);

		return result;
	}
};

int main()
{
	auto sol = new Solution();
	sol->print(sol->combinationSum3(3, 20));
}