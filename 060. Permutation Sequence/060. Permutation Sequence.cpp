// 060. Permutation Sequence.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

/*
The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:

	void dfs(int &index, vector<bool> &visit, vector<int> &ans, int n, int k, string &result)
	{
		if (index > k)
		{
			return;
		}

		if (ans.size() == n)
		{
			index++;
			if (index == k)
			{
				for (int i = 0; i < ans.size(); i++)
				{
					result += to_string(ans[i]);
				}
			}
		}
		else if (ans.size() < n)
		{
			//for (int i = 0; i < input.size(); ++i)
			for (int i = 1; i <= n; i++)
			{
				if (!visit[i])
				{
					visit[i] = true;
					ans.push_back(i);
					dfs(index, visit, ans, n, k, result);
					if (!result.empty())
					{
						return;
					}
					ans.pop_back();
					visit[i] = false;
				}
			}
		}
	}

	string getPermutation(int n, int k)
	{
		vector<bool> visit(n+1);
		vector<int> input(n+1);
		vector<int> ans;

		//for (int i = 0; i < n; i++)
		//{
		//	input[i] = i + 1;
		//	visit[i] = false;
		//}

		int index = 0;
		string result;
		dfs(index, visit, ans, n, k, result);

		return result;
	}
};

int main()
{
	auto sol = new Solution();
	cout << sol->getPermutation(3, 3).c_str() << endl;
    return 0;
}

