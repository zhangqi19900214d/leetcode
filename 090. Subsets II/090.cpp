#include <vector>
#include <iostream>
using namespace std;

/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
[2],
[1],
[1,2,2],
[2,2],
[1,2],
[]
]
*/

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums)
	{
		vector<vector<int>> result;

		if (nums.size() == 0)
		{
			return result;
		}
		else if (nums.size() == 1)
		{
			result.push_back(nums);
			return result;
		}
		else
		{
			int cur = nums[0];
			vector<vector<int>> sub_result = this->subsetsWithDup(vector<int>(nums.begin() + 1, nums.end()));

			for (int i = 0; i < sub_result.size(); ++i)
			{
				vector<int> item = sub_result[i];
				result.push_back(item);

				for (int j = 0; j <= item.size(); ++j)
				{
					vector<int> res = item;
					res.insert(res.begin() + j, cur);
					result.emplace_back(res);
				}
			}
			return result;
		}
	}
};

int main()
{
	auto sol = new Solution();
	vector<int> nums{ 1, 2, 2 };

	auto res = sol->subsetsWithDup(nums);
	for (auto item : res)
	{
		for (auto n : item)
		{
			cout << n << " ";
		}
		cout << endl;
	}
}