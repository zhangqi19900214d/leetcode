/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn¡¯t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.

Accepted
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
	void print(vector<vector<char>>& board)
	{
		for (auto &iter : board)
		{
			for (auto &v : iter)
			{
				cout << v << " ";
			}
			cout << endl;
		}
	}

	bool dfs(int x, int y, vector<vector<bool>> &visit, vector<pair<int, int>> &ans, vector<vector<char>> &board)
	{
		const int N = board.size();
		const int M = board[0].size();
		static vector<pair<int, int>> step{ { 0, -1 },{ 1, 0 },{ 0, 1 },{ -1, 0 } };

		if ((x * y == 0 || x == N - 1 || y == M - 1) && board[x][y] == 'O')
		{
			return false;
		}

		ans.push_back(make_pair(x, y));

		for (int k = 0; k < step.size() && ans.size() > 0; ++k)
		{
			int step_x = x + step[k].first;
			int step_y = y + step[k].second;

			if (step_x >= 0 && step_y >= 0 && step_x < N && step_y < M && !visit[step_x][step_y])
			{
				if (board[step_x][step_y] == 'O')
				{
					if (step_x * step_y == 0 || step_x == N - 1 && step_y == M - 1)
					{
						return false;
					}
					
					visit[step_x][step_y] = true;
					if (!dfs(step_x, step_y, visit, ans, board))
					{
						visit[step_x][step_y] = false;
						return false;
					}
					//visit[step_x][step_y] = false; //¼ôÖ¦
				}
			}
		}

		return true;
	}

	void solve(vector<vector<char>> &board)
	{
		if (board.size() < 1)
		{
			return ;
		}

		const int N = board.size();
		const int M = board[0].size();
		vector<vector<bool>> visit(N, vector<bool>(M, false));

		for (int x = 1; x < N-1; x++)
		{
			for (int y = 1; y < M-1; y++)
			{
				if (board[x][y] == 'O' && !visit[x][y])
				{
					if (x == 3 & y == 3)
					{
						x += 10;
						x -= 10;
					}
					vector<pair<int, int>> ans;
					if (dfs(x, y, visit, ans, board))
					{
						for (auto &pos : ans)
						{
							board[pos.first][pos.second] = 'X';
						}
					}
				}
			}
		}
	}
};

int main()
{
	auto sol = new Solution();
	vector<vector<char>> board1{
		{ 'X','X','X','X' },
		{ 'X','O','O','X' },
		{ 'X','X','O','O' },
		{ 'X','O','X','X' }
	};

	vector<vector<char>> board2{
		{ 'X','X','X' },
		{ 'X','O','X' },
		{ 'X','X','X' }
	};
	
	vector<vector<char>> board3{
		{'X','O','X'},
		{'X','O','X'},
		{'X','O','X'}
	};

	vector<vector<char>> board4{
		{ 'X','X','X','X' },
		{ 'X','O','O','X' },
		{ 'X','X','O','X' },
		{ 'X','O','X','X' }
	};

	vector<vector<char>> board5{
		{ 'X','X','X' },
		{ 'O','O','X' },
		{ 'X','X','X' }
	};

	vector<vector<char>> board6{
		{ 'O','X','X','O','X' },
		{ 'X','O','O','X','O' },
		{ 'X','O','X','O','X' },
		{ 'O','X','O','O','O' },
		{ 'X','X','O','X','O' },
	};

	vector<vector<char>> board7{
		{ 'O','O','O','O','X','X' },
		{ 'O','O','O','O','O','O' },
		{ 'O','X','O','X','O','O' },
		{ 'O','X','O','O','X','O' },
		{ 'O','X','O','X','O','O' },
		{ 'O','X','O','O','O','O' }
	};

	auto &board = board7;

	sol->print(board);

	sol->solve(board);
	cout << endl;

	sol->print(board);
}