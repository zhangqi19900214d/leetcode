/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, 
determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:

	bool wordBreak(string s, vector<string> &wordDict)
	{
		vector<bool>dp(s.size() + 1);
		dp[0] = true;

		for (int i = 1; i < s.size() + 1; i++)
		{
			for (int j = 0; j < i; j++)
			{
				string sub = s.substr(j, i - j);
				if (dp[j] && std::find(wordDict.begin(), wordDict.end(), sub) != wordDict.end())
				{
					dp[i] = true;
					break;
				}
			}
		}

		return dp[s.size()];
	}
};

int main()
{
	auto sol = new Solution();
	cout << sol->wordBreak("cars", vector<string>{"car", "ca", "rs"}) << endl;
	cout << sol->wordBreak("applepenapple", vector<string>{"apple", "pen"}) << endl;
	cout << sol->wordBreak("catsandog", vector<string>{"cats", "dog", "sand", "and", "cat"}) << endl;
	//cout << sol->wordBreak("bccdbacdbdacddabbaaaadababadad", vector<string>{"cbc", "bcda", "adb", "ddca", "bad", "bbb", "dad", "dac", "ba", "aa", "bd", "abab", "bb", "dbda", "cb", "caccc", "d", "dd", "aadb", "cc", "b", "bcc", "bcd", "cd", "cbca", "bbd", "ddd", "dabb", "ab", "acd", "a", "bbcc", "cdcbd", "cada", "dbca", "ac", "abacd", "cba", "cdb", "dbac", "aada", "cdcda", "cdc", "dbc", "dbcb", "bdb", "ddbdd", "cadaa", "ddbc", "babb"}) << endl;
	//cout << sol->wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", vector<string>{"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"}) << endl;
}