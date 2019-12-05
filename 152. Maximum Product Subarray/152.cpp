/*Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int maxProduct(vector<int>& nums)
	{
		if (nums.size() < 1)
		{
			return 0;
		}

		vector<int> max_dp(nums.size());
		vector<int> min_dp(nums.size());

		int m = nums[0];
		max_dp[0] = nums[0];
		min_dp[0] = nums[0];

		for (int i = 1; i < nums.size(); i++)
		{
			max_dp[i] = max(nums[i], max(nums[i] * min_dp[i - 1], nums[i] * max_dp[i - 1]));
			min_dp[i] = min(nums[i], min(nums[i] * min_dp[i - 1], nums[i] * max_dp[i - 1]));

			m = max(max(max_dp[i], min_dp[i]), m);
			//cout << max_dp[i] << " " << min_dp[i] << endl;
		}
		return m;
	}
};

int main()
{
	auto sol = new Solution();
	cout << sol->maxProduct(vector<int>{ 2,3,-2,4 }) << endl;
	cout << sol->maxProduct(vector<int>{ -2, 0, -2}) << endl;
	cout << sol->maxProduct(vector<int>{ -2, 3, -4}) << endl;


}