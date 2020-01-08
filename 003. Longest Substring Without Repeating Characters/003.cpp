/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        vector<int> dp(s.size() + 1, 1);
        int max_len = dp[0];

        for (int i = 1; i < s.size(); i++)
        {
            bool rep = false;
            for (int j = i - 1; j >= i - dp[i - 1]; j--)
            {
                if (s[i] == s[j])
                {
                    rep = true;
                    dp[i] = i - j;
                    break;
                }
            }

            if (!rep)
            {
                dp[i] = dp[i - 1] + 1;
            }

            max_len = max_len > dp[i] ? max_len : dp[i];
        }

        return max_len;
    }
};

int main()
{
    auto sol = new Solution();
    cout << sol->lengthOfLongestSubstring("pwwkew") << endl;
    cout << sol->lengthOfLongestSubstring("bbb") << endl;
}