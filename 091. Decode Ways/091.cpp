/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
*/

#include <stack>
#include <set>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution 
{
public:
	void dfs(int start, stack<char> &ans, int &result, const string &input)
	{
		if (start != ans.size()) // 已经检测到非法了，提前结束
		{
			return;
		}
		if (ans.size() == input.size()) //最后一个
		{
			result++;
			cout << result << endl;
			return;
		}

		if (input[start] != '0') //0肯定不能出现在首位
		{
			ans.push(input[start]);
			dfs(start + 1, ans, result, input);

			if (start < input.size() - 1)
			{
				string t = input.substr(start, 2);
				int k = atoi(t.c_str());

				if (k > 0 && k <= 26)
				{
					ans.push(input[start + 1]);
					dfs(start + 2, ans, result, input);
					ans.pop();
				}
			}
			ans.pop();
		}
	}

	int numDecodings1(string s) 
	{
		if (s.empty())
		{
			return 0;
		}
		stack<char> ans;
		int result = 0;

		dfs(0, ans, result, s);
		
		return result;
	}

	string eraseZeros(string &s)
	{
		string input = s;
		size_t pos = input.find("0");

		while (pos != string::npos)
		{
			if (pos != string::npos)
			{
				if (pos == 0)
				{
					return "";
				}

				string t = input.substr(pos - 1, 2);
				if (atoi(t.c_str()) > 26 || atoi(t.c_str()) < 1)
				{
					return "";
				}

				input = input.substr(0, pos - 1) + "#" + input.substr(pos + 1, -1);
			}

			pos = input.find("0");
		}
		return input;
	}

	int numDecodings(string s)
	{
		string input = this->eraseZeros(s);

		if (input.empty())
		{
			return 0;
		}

		vector<int> dp(input.size());
		
		if (input.size() < 2)
		{
			return 1;
		}

		int pos = input.size() - 1;
		string str;
		str = input.substr(pos - 1, 2);

		if (str[0] != '#' && str[1] != '#')
		{
			dp[pos] = 1;
			dp[pos - 1] = 1;
			if (atoi(str.c_str()) < 27)
			{
				dp[pos - 1] = 2;
			}
		}
		else
		{
			dp[pos] = 1;
			dp[pos - 1] = 1;
		}

		for (pos = pos - 2; pos >= 0; pos--)
		{
			str = input.substr(pos, 2);
			dp[pos] = dp[pos + 1];

			if (str[0] != '#' && str[1] != '#' && atoi(str.c_str()) <= 26)
			{
				dp[pos] = dp[pos + 1] + dp[pos + 2];
			}
		}

		return dp[0];
	}
};


int main()
{
	auto sol = new Solution();
	cout << sol->numDecodings("1029") << endl;
	cout << sol->numDecodings("110") << endl;
	//cout << sol->numDecodings("1232424131") << endl;
	//cout << sol->numDecodings("226") << endl;
	//cout << sol->numDecodings("103") << endl;
	//cout << sol->numDecodings("10") << endl;
	//cout << sol->numDecodings("10") << endl;
	//cout << sol->numDecodings("110") << endl;
	//cout << sol->numDecodings("12120") << endl;
	cout << sol->numDecodings("6065812287883668764831544958683283296479682877898293612168136334983851946827579555449329483852397155") << endl;
	cout << sol->numDecodings("6165812287883668764831544958683283296479682877898293612168136334983851946827579555449329483852397155") << endl;
	cout << sol->numDecodings("4757562545844617494555774581341211511296816786586787755257741178599337186486723247528324612117156948") << endl;
	cout << sol->numDecodings("1787897759966261825913315262377298132516969578441236833255596967132573482281598412163216914566534565") << endl;
}