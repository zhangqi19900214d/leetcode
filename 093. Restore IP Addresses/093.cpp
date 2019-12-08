/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

Example:

Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]

*/
#include <string>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
	void dfs(int start, vector<string> &ans, vector<string> &result, const string &s)
	{
		if (ans.size() > 4 || start > s.size())
		{
			return;
		}

		if (start == s.size() && ans.size() == 4)
		{
			string ipv4;
			for (auto i : ans)
			{
				ipv4 += "." + i;
			}
			result.push_back(ipv4.substr(1, -1));
			return;
		}
		
		//for (int k = 1; k < 4 && start < s.length(); k++)
		//{
		//	string seg = s.substr(start, k);
		//	//cout << seg << " ";
		//	if (ans.size() < 4 && seg[0] != '0' && atoi(seg.c_str()) > 0 && atoi(seg.c_str()) <= 255)
		//	{
		//		ans.push_back(seg);
		//		dfs(start + k, ans, result, s);
		//		ans.pop_back();
		//	}
		//}


		//for(int i = start; i < s.length(); i++) //这里的dfs为什么不用for循环
		string sub1 = s.substr(start, 1);
		ans.push_back(sub1);
		dfs(start + 1, ans, result, s);
		ans.pop_back();

		string sub2 = s.substr(start, 2);
		if (sub2.length() == 2 && sub2[0] != '0' && ans.size() < 4)
		{
			ans.push_back(sub2);
			dfs(start + 2, ans, result, s);
			ans.pop_back();
		}

		string sub3 = s.substr(start, 3);
		if (sub3.length() == 3 && sub3[0] != '0' && atoi(sub3.c_str()) <= 255 && ans.size() < 4)
		{
			ans.push_back(sub3);
			dfs(start + 3, ans, result, s);
			ans.pop_back();
		}
	}

	vector<string> restoreIpAddresses(string s)
	{
		vector<string> ans;
		vector<string> result;
		dfs(0, ans, result, s);

		return result;
	}
};

int main()
{
	auto sol = new Solution();
	auto result = sol->restoreIpAddresses("1234");

	for (auto item : result)
	{
		cout << item << endl;
	}
}