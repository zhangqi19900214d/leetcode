/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
["aa","b"],
["a","a","b"]
]
palindrome : ╩ьнд
*/

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:

	void print(vector<vector<string>> &result)
	{
		for (auto &item : result)
		{
			for (auto &v : item)
			{
				cout << v.c_str() << " ";
			}
			cout << endl;
		}
	}

	void dfs(int start, string &ans, vector<string> &result, const string &s)
	{
		if (start > s.size())
		{
			return;
		}
		
		if (ans.size() > 0)
		{
			//cout << ans.c_str() << " ";
			string tmp = ans;
			reverse(tmp.begin(), tmp.end());
			if (tmp == ans)
			{
				result.push_back(ans);
			}
		}
		
		for (int i = 0; i < s.size(); i++)
		{
			ans = s.substr(start, i+1);
			//cout << ans.c_str() << endl;
			dfs(start + i+1, ans, result, s);
		}
	}
	
	vector<vector<string>> partition(string s)
	{
		vector<vector<string>> result;
		for (int i = 0; i < s.size(); i++)
		{
			string ans;
			vector<string> res;
			dfs(i, ans, res, s);
			result.push_back(res);
		}
		return result;
	}
};

int main()
{
	auto sol = new Solution();
	sol->print(sol->partition("aab"));

}