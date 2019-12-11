/*
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
    [1],
   [1,1],
  [1,2,1],
 [1,3,3,1],  3
[1,4,6,4,1]
]
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

	void print(vector<vector<int>> &triangle)
	{
		for (int r = 0; r < triangle.size(); r++)
		{
			int k = (triangle.size() - r);
			while (k-- > 0)
			{
				cout << " ";
			}

			for (int c = 0; c < triangle[r].size(); ++c)
			{
				cout << triangle[r][c] << ",";
			}
			cout << "\b " << endl;
		}
	}

	vector<vector<int>> generate(int numRows)
	{
		vector<vector<int>> triangle(numRows);
		
		for (int i = 0; i < numRows; i++)
		{
			triangle[i].resize(i+1);
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

		return triangle;
	}
};

int main()
{
	auto sol = new Solution();
	sol->print(sol->generate(6));
}