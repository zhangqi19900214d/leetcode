/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
[2],
[3,4],
[6,5,7],
[4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:

	int minimumTotal(vector<vector<int>>& triangle)
	{
		if (triangle.empty())
		{
			return 0;
		}

		vector<vector<int>> dp(triangle.size());
		
		for (int r = 0; r < triangle.size(); ++r)
		{
			dp[r].resize(r + 1);
		}

		dp[0][0] = triangle[0][0];

		for (int r = 1; r < triangle.size(); ++r)
		{
			dp[r][0] = dp[r - 1][0] + triangle[r][0];
			dp[r][r] = dp[r - 1][r-1] + triangle[r][r];

			for (int c = 1; c < r; c++)
			{
				dp[r][c] = min(dp[r - 1][c - 1], dp[r - 1][c]) + triangle[r][c];
			}
		}

		int value = dp[triangle.size() -1][0];
		for (int c = 1; c < dp[triangle.size() - 1].size(); ++c)
		{
			value = min(value, dp[triangle.size() - 1][c]);
		}

		return value;
	}
};

int main()
{
	auto sol = new Solution();
	vector<vector<int>> triangle{ 
		    {2},
		   {3,4},
		  {6,5,7},
		 {4,1,8,3},
		{5,6,6,6,1}
	};

	//cout << sol->minimumTotal(triangle) << endl;
	cout << sol->minimumTotal(vector<vector<int>>{ {1}}) << endl;

	return 0;
}