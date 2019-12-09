/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input:
[
[1,1,1],
[1,0,1],
[1,1,1]
]
Output:
[
[1,0,1],
[0,0,0],
[1,0,1]
]
Example 2:

Input:
[
[0,1,2,0],
[3,4,5,2],
[1,3,1,5]
]
Output:
[
[0,0,0,0],
[0,4,5,0],
[0,3,1,0]
]
Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

*/

#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
	void  print(vector<vector<int>>& matrix)
	{
		for (auto item : matrix)
		{
			for (auto k : item)
			{
				cout << k << " ";
			}
			cout << endl;
		}
	}

	void setZeroes(vector<vector<int>>& matrix)
	{
		if (matrix.size() == 0)
		{
			return;
		}

		vector<bool> row(matrix.size(), 1);
		vector<bool> col(matrix[0].size(), 1);

		for (int i = 0; i < matrix.size(); ++i)
		{
			for (int j = 0; j < matrix[0].size(); ++j)
			{
				if (matrix[i][j] == 0)
				{
					row[i] = 0;
					col[j] = 0;
				}
			}
		}

		for (int i = 0; i < matrix.size(); ++i)
		{
			if (row[i] == 0)
			{
				for (int j = 0; j < matrix[0].size(); ++j)
				{
					matrix[i][j] = 0;
				}
			}
		}

		for (int i = 0; i < matrix[0].size(); ++i)
		{
			if (col[i] == 0)
			{
				for (int j = 0; j < matrix.size(); ++j)
				{
					matrix[j][i] = 0;
				}
			}
		}
	}
};

int main()
{
	auto sol = new Solution();
	vector<vector<int>> matrix{ {1,1,1}, {1,0,1}, {1,1,1} };
	
	sol->setZeroes(matrix);

	sol->print(matrix);
}