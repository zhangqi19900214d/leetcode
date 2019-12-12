/*
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

Input: nums =
[
[9,9,4],
[6,6,8],
[2,1,1]
]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:

Input: nums =
[
[3,4,5],
[3,2,6],
[2,2,1]
]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
*/
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	int dfs(int x, int y, vector<vector<bool>> &visit, vector<vector<int>> &dp, vector<vector<int>>& matrix)
	{
		const int N = matrix.size();
		const int M = matrix[0].size();

		static vector<pair<int, int>> step{ { 0, -1 },{ 1, 0 },{ 0, 1 },{ -1, 0 } };

		int path = 1;
		for (int i = 0; i < 4; i++)
		{
			int step_x = x + step[i].first;
			int step_y = y + step[i].second;

			if (step_x >= 0 && step_y >= 0 && step_x < N && step_y < M && matrix[step_x][step_y] > matrix[x][y] && !visit[step_x][step_y])
			{
				if (dp[step_x][step_y] != 0)
				{
					path = max(path, dp[step_x][step_y] + 1);
				}
				else
				{
					visit[step_x][step_y] = true;
					int t = dfs(step_x, step_y, visit, dp, matrix) + 1;
					path = max(path, t);
					visit[step_x][step_y] = false;
				}
			}
		}

		dp[x][y] = path;
		return path;
	}

	int longestIncreasingPath(vector<vector<int>>& matrix)
	{
		if (matrix.empty())
		{
			return 0;
		}

		const int N = matrix.size();
		const int M = matrix[0].size();

		vector<vector<bool>> visit(N, vector<bool>(M));
		vector<vector<int>> dp(N, vector<int>(M, 0));

#if 0
		for (auto item : matrix)
		{
			for (auto v : item)
			{
				cout << v << " ";
			}
			cout << endl;
		}
#endif

		for (int r = 0; r < N; ++r)
		{
			for (int c = 0; c < M; ++c)
			{
				dfs(r, c, visit, dp, matrix);
			}
		}

		int max_path = 0;
		for (auto item : dp)
		{
			for (auto v : item)
			{
				//cout << v << " ";
				max_path = max(max_path, v);
			}
			//cout << endl;
		}

		return max_path;
	}
};

int main()
{
	auto sol = new Solution();

	vector<vector<int>> matrix{
		{ 18,17,14,11,10,15,14 },
		{ 16,18, 0,17,17,18,12 },
		{  2,18,18, 7, 7,15,17 },
		{ 18, 7,10, 6,14, 2,14 },
		{ 16,18,11,15,12, 0, 9 },
		{ 17,15,13,13,19,17,16 },
		{  0, 9,10, 0, 5, 1, 7 }
	};

	/*vector<vector<int>> matrix{
		{  0,  1,  2,  3,  4,  5,  6,  7,  8,  9},
		{ 19, 18, 17, 16, 15, 14, 13, 12, 11, 10},
		{ 20, 21, 22, 23, 24, 25, 26, 27, 28, 29},
		{ 39, 38, 37, 36, 35, 34, 33, 32, 31, 30},
		{ 40, 41, 42, 43, 44, 45, 46, 47, 48, 49},
		{ 59, 58, 57, 56, 55, 54, 53, 52, 51, 50},
		{ 60, 61, 62, 63, 64, 65, 66, 67, 68, 69},
		{ 79, 78, 77, 76, 75, 74, 73, 72, 71, 70},
		{ 80, 81, 82, 83, 84, 85, 86, 87, 88, 89},
		{ 99, 98, 97, 96, 95, 94, 93, 92, 91, 90},
		{100,101,102,103,104,105,106,107,108,109},
		{119,118,117,116,115,114,113,112,111,110},
		{120,121,122,123,124,125,126,127,128,129},
		{139,138,137,136,135,134,133,132,131,130},
		//{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0}
	};*/

	cout << sol->longestIncreasingPath(matrix) << endl;
}