/*
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

Example 1:

Input: "3+2*2"
Output: 7
Example 2:

Input: " 3/2 "
Output: 1
Example 3:

Input: " 3+5 / 2 "
Output: 5
Note:

You may assume that the given expression is always valid.
Do not use the eval built-in library function.
*/

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
	void eraseSpace(string &s)
	{
		size_t p = 0;
		size_t q = 0;

		for (; p < s.size();)
		{
			if (s[p] == ' ')
			{
				p++;
			}
			else
			{
				s[q++] = s[p++];
			}
		}
		s = s.substr(0, q);
	}

	pair<string, int> getA(const string &s, int index)
	{
		int end = index;
		int flag = 1;
		index--;

		while (index >= 0 && s[index] >= '0' && s[index] <= '9')
		{
			index--;
		}
		if (end == index + 1)
		{
			return make_pair("", 0);
		}

		int start = index+1;

		while (index >= 0 && (s[index] == '+' || s[index] == '-'))
		{
			if (s[index] == '-')
			{
				flag *= -1;
			}

			index--;
		}

		index++;

		if (flag == -1)
		{
			return make_pair("-" + s.substr(start, end - start), index);
		}
		else
		{
			return make_pair(s.substr(start, end - start), index);
		}
	}
	
	pair<string, int> getB(const string &s, int index)
	{
		int flag = 1;
		index++;
		while (index < s.size() && s[index] == '+' || s[index] == '-')
		{
			if (s[index] == '-')
			{
				flag *= -1;
			}

			index++;
		}

		int start = index;

		while (index < s.size() && s[index] >= '0' && s[index] <= '9')
		{
			index++;
		}

		if (flag == -1)
		{
			return make_pair("-" + s.substr(start, index - start), index);
		}
		else
		{
			return make_pair(s.substr(start, index - start), index);
		}
	}
	int calculate(string s)
	{
		this->eraseSpace(s);

		for (int i = 1; i < s.size(); i++)
		{
			if (s[i] == '*' || s[i] == '/')
			{
				auto a = this->getA(s, i);
				auto b = this->getB(s, i);

				if (a.first.size() > 0 && b.first.size() > 0)
				{
					int ans = s[i] == '*' ? stoll(a.first) * stoll(b.first) : stoll(a.first) / stoll(b.first);
					s = s.substr(0, a.second) + (ans >= 0 ? "+" : "") + to_string(ans) + s.substr(b.second, -1);
					i = a.second;
				}
			}
		}

		s += "+0";
		int sum = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '+' || s[i] == '-')
			{
				auto a = this->getA(s, i);
				if (a.first.size() > 0)
				{
					sum += stoll(a.first);
				}
			}
		}

		return sum;
	}
};

int main()
{
	auto sol = new Solution();
	//cout << sol->calculate("1*2-3/4+5*6-7*8+9/10") << endl;
	//cout << sol->calculate("1 + 7 - 7 + 3 + 3 + 6 - 3 + 1 - 8 - 2 - 6 - 1 + 8 - 0 + 0 - 2 + 0 + 10 - 6 - 9 - 9 + 0 + 6 + 4 + 2 + 7 + 1 - 4 - 6 - 6 - 0 + 6 + 3 - 7 + 0 - 4 + 10 - 2 - 5 + 6 - 1 - 3 + 7 + 7 + 2 + 0 + 2 - 8 + 7 + 2 - 3 - 8 - 9 - 6 + 10 - 7 - 6 + 3 - 8 + 5 + 6 - 7 - 10 - 6 - 8 - 10 - 8 + 1 + 9 + 1 - 9 - 1 + 10 + 10 + 3 + 7 - 1 - 10 + 1 - 0 - 7 + 0 - 3 - 3 + 4 + 7 - 9 - 10 - 1 + 4 - 8 - 3 - 0 - 1 - 0 - 3 + 5 - 10 + 6 - 6 - 0 - 6 - 6 - 7 + 7 + 10 + 10 - 5 - 9 - 10 - 2 - 8 + 9 - 2 - 8 - 7 - 9 - 0 - 6 - 5 - 1 + 1 + 3 + 8 - 5 - 8 + 3 - 9 + 9 + 6 - 5 + 0 - 2 + 0 + 8 + 8 - 4 + 6 + 1 - 2 - 0 - 10 - 8 + 1 - 2 - 8 + 2 - 2 - 2 - 4 + 2 + 5 + 3 - 9 + 1 + 9 - 8 + 9 - 8 + 7 + 10 + 1 + 10 - 9 + 2 + 2 + 8 + 7 - 10 - 8 + 6 + 6 + 3 + 0 + 4 - 1 + 0 + 7 - 3 + 8 - 8 - 4 + 8 - 6 - 6 + 3 - 3 - 9 + 6 + 4 + 6 + 7 - 2 - 0 + 6 - 10 + 8 - 2 - 4 + 3 - 8 + 1 - 2 + 8 + 1 - 2 - 4 - 3 - 9 - 4 - 1 - 3 + 5 + 9 + 7 - 8 - 2 + 7 - 10 + 7 + 9 + 1 + 5 - 5 + 8 - 3 - 10 - 7 - 1 - 7 + 10 + 3 + 2 - 8 - 8 + 0 + 9 + 3 + 6 + 8 + 4 + 2 + 10 + 8 + 6 - 1 + 2 + 10 - 5 + 5 + 4 - 2 + 10 + 7 - 6 - 5 + 9 - 9 + 5 - 5 - 2 + 5 + 2 - 1 + 7 - 8 + 4 - 2 + 2 + 2 + 5 - 10 - 7 - 0 + 5 - 8 - 6 - 10 - 5 + 9 - 1 + 1 - 8 + 10 - 7 + 2 - 3 - 3 + 2 + 3 - 8 + 4 - 6 - 7 + 3 - 0 + 6 - 6 - 3 + 1 + 2 - 6 + 2 + 3 + 0 - 4 - 0 + 3 - 5 - 1 - 4 - 0 + 9 + 5 - 6 + 3 - 10 + 0 + 10 - 4 + 6 - 6 - 5 - 6 + 5 + 3 + 7 - 4 + 6 + 2 + 0 + 10 + 4 - 3 + 10 - 10 - 0 - 10 - 4 - 8 + 9 - 5 - 0 - 0 - 9 - 8 - 3 - 2 + 6 - 2 + 5 - 4 - 6 + 7 - 8 + 8 - 8 + 10 - 0 + 10 - 3 - 9 - 5 + 0 + 10 + 6 + 9 - 3 - 0 - 8 + 4 + 5 - 4 - 9 + 0 - 2 - 3 - 0 - 9 + 1 - 4 - 1 - 6 - 9 + 1 - 0 - 0 - 5 + 1 - 6 + 1 + 6 + 0 - 4 - 9 + 10 + 2 + 0 - 8 + 0 - 10 - 3 + 5 + 6 - 3 + 5 - 1 - 0 + 6 - 5 + 5 - 0 + 0 - 4 - 1 - 0 - 4 - 6") << endl;
	cout << sol->calculate("1+2") << endl;
	//cout << sol->calculate("----+3+----+4") << endl;
	//cout << sol->calculate("-+5/----+2 ") << endl;
}