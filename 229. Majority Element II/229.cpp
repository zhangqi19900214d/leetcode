/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Note: The algorithm should run in linear time and in O(1) space.

Example 1:

Input: [3,2,3]
Output: [3]
Example 2:

Input: [1,1,1,3,3,2,2,2]
Output: [1,2]
*/
#include <vector>
#include <iostream>

using namespace std;

class Solution 
{
public:
	void print(vector<int> &result)
	{
		for (auto &v : result)
		{
			cout << v << " ";
		}
		cout << endl;
	}

	vector<int> majorityElement(vector<int>& nums)
	{
		vector<int> result;
		if (nums.size() < 1)
		{
			return result;
		}

		int v1 = 0;
		int v2 = 0;
		
		int c1 = -1;
		int c2 = -1;

		for (int i = 0; i < nums.size(); i++)
		{
			if (c1 > 0 && nums[i] == v1)
			{
				c1++;
			}
			else if (c2 > 0 && nums[i] == v2)
			{
				c2++;
			}
			else if (c1 <= 0)
			{
				v1 = nums[i];
				c1 = 1;
			}
			else if (c2 <= 0)
			{
				v2 = nums[i];
				c2 = 1;
			}
			else
			{
				c1--;
				c2--;
			}
		}

		c1 = c2 = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == v1)
			{
				c1++;
			}
			else if (nums[i] == v2)
			{
				c2++;
			}
		}

		if (c1 > nums.size() / 3)
		{
			result.push_back(v1);
		}

		if (c2 > nums.size() / 3)
		{
			result.push_back(v2);
		}

		return result;
	}
};

int main()
{
	auto sol = new Solution();
	sol->print(sol->majorityElement(vector<int>{1, 2, 1, 3, 3, 2, 1, 2}));
	sol->print(sol->majorityElement(vector<int>{8, 8, 7, 7, 7}));
	sol->print(sol->majorityElement(vector<int>{0, 3, 4, 0}));
}
