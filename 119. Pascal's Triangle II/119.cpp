/*
Given a non-negative index k where k ¡Ü 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex)
	{
		int numRows = rowIndex + 1;
		vector<vector<int>> triangle(numRows);

		for (int i = 0; i < numRows; i++)
		{
			triangle[i].resize(i + 1);
			triangle[i][0] = 1;
			triangle[i][i] = 1;
		}

		for (int r = 2; r < numRows; ++r)
		{
			for (int c = 1; c < r; ++c)
			{
				triangle[r][c] = triangle[r - 1][c - 1] + triangle[r - 1][c];
			}
		}

		return triangle[rowIndex];
	}
};

int main()
{
	auto sol = new Solution();
	auto res = sol->getRow(3);
	for (auto k : res)
	{
		cout << k << " ";
	}
	cout << endl;

}