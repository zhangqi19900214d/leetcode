#include <vector>
#include <iostream>

using namespace std;

/*
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
[1,2,3],
[1,3,2],
[2,1,3],
[2,3,1],
[3,1,2],
[3,2,1]
]
*/

class Solution {
public:

	vector<vector<int>> permute(vector<int>& nums)
	{
		vector<vector<int>> result;

		if (nums.size() == 0)
		{
			return result;
		}
		else if(nums.size() == 1)
		{
			result.push_back(nums);
			return result;
		}
		else
		{
			int cur = nums[0];
			vector<int> sub(nums.begin() + 1, nums.end());

			vector<vector<int>> sub_result = this->permute(sub);

			for (int i = 0; i < sub_result.size(); ++i)
			{
				vector<int> item = sub_result[i];

				for (int j = 0; j <= item.size(); ++j)
				{
					vector<int> res = item;
					res.insert(res.begin() + j, cur);
					result.emplace_back(res);
				}
			}
		}

		return result;
	}
};

int main()
{
	auto sol = new Solution();
	vector<int> nums { 1, 2, 3, 4 };
	//vector<int> nums{ 1,2,3 };
	//auto res = sol->permute(nums.begin(), nums.end());
	auto res = sol->permute(nums);

	for (auto item : res)
	{
		for (auto x : item)
		{
			cout << x << " ";
		}
		cout << endl;
	}
}