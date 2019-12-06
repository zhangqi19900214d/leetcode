/*Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

*/

#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
	string decodeString(string s)
	{
		int end = s.find("]");
		if (end == string::npos)
		{
			return s;
		}

		int start = end;
		while (start >= 0 && s[start] != '[')
		{
			start--;
		}

		int n = 1;
		int k = 0;
		if (start > 0)
		{
			k = start - 1;
			while (k >= 0 && (s[k] >= '0' &&s[k] <= '9'))
			{
				k--;
			}
			k++;
			start++;

			n = atoi(s.substr(k, start - k - 1).c_str());
		}
		//cout << start << " " << end << endl;
		//cout << n << " " << s.substr(start, end - start) << endl;
		string sub = s.substr(start, end - start);

		string result = s.substr(0, k);
		while (n--)
		{
			result += sub;
		}
		result += s.substr(end + 1, -1);

		return decodeString(result);
	}
};


int main()
{
	auto sol = new Solution();
	cout << sol->decodeString("s") << endl;
	cout << sol->decodeString("23[da]2[bc]") << endl;
	cout << sol->decodeString("3[a2[c]]") << endl;
	cout << sol->decodeString("2[abc]3[cd]ef") << endl;
}


