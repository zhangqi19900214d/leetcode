/*
Given an input string, reverse the string word by word.



Example 1:

Input: "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
*/

#include <stack>
#include <string>
#include <iostream>

using namespace std;

using namespace std;

class Solution
{
public:
	string reverseWords(string s)
	{
		stack<string> result;
		size_t start = 0;
		while (true)
		{
			while (start < s.length() && s[start] == ' ')
			{
				start += 1;
			}

			size_t end = start;
			if (start < s.length())
			{
				while (end < s.length() && s[end] != ' ')
				{
					end += 1;
				}
				if (end <= s.length())
				{
					result.push(s.substr(start, end - start));
				}
			}

			if (start >= s.length())
			{
				break;
			}
			start = end + 1;
		}

		string ret;
		while (!result.empty())
		{
			ret += " " + result.top();
			result.pop();
		}

		return ret.empty() ? "" : ret.substr(1, -1);
	}
};

int main()
{
	auto sol = new Solution();
	//sol->reverseWords(" hello world!  ");
	cout << sol->reverseWords(" hello world!  ").c_str() << endl;
	cout << sol->reverseWords("a good   example").c_str() << endl;
	cout << sol->reverseWords(" a good   example ").c_str() << endl;

}