/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
*/


#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
	void dfs(int x, int y, vector<vector<bool>> &visit, vector<vector<char>>& grid)
	{
		const int N = grid.size();
		const int M = grid[0].size();
		static vector<pair<int, int>> step{ { 0, -1 },{ 1, 0 },{ 0, 1 },{ -1, 0 } };

		if (x >= N || y >= M)
		{
			return;
		}

		for (int k = 0; k < step.size(); ++k)
		{
			int step_x = x + step[k].first;
			int step_y = y + step[k].second;

			if (step_x >= 0 && step_y >= 0 && step_x < N && step_y < M && !visit[step_x][step_y] && grid[step_x][step_y] == '1')
			{
				visit[step_x][step_y] = true;
				dfs(step_x, step_y, visit, grid);
			}
		}
	}

	int numIslands(vector<vector<char>>& grid)
	{
		if (grid.size() < 1)
		{
			return 0;
		}

		const int N = grid.size();
		const int M = grid[0].size();
		vector<vector<bool>> visit(N, vector<bool>(M, false));

		int num = 0;
		for (int x = 0; x < N; x++)
		{
			for (int y = 0; y < M; y++)
			{
				if (grid[x][y] == '1' && !visit[x][y])
				{
					num++;
					dfs(x, y, visit, grid);
				}
			}
		}

#if 0
		for (auto iter : visit)
		{
			for (auto v : iter)
			{
				cout << v << " ";
			}
			cout << endl;
		}
#endif

		return num;
	}
};

int main()
{
	auto sol = new Solution();
	//vector<vector<char>> grid{
	//	{'1','1','1','1','0'},
	//	{'1','1','0','1','0'},
	//	{'1','1','0','0','0'},
	//	{'0','0','0','0','0'},
	//};

	vector<vector<char>> grid{
		{'1','1','0','0','0'},
		{'1','1','0','0','0'},
		{'0','0','1','0','0'},
		{'0','0','0','1','1'}, 
	};

	cout << sol->numIslands(grid) << endl;

}