/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

Example:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"

Output: ["AAAAACCCCC", "CCCCCAAAAA"]
*/

#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	void print(vector<string> &result)
	{
		for (auto iter : result)
		{
			cout << iter << endl;
		}
	}

	vector<string> findRepeatedDnaSequences(string s)
	{
		unordered_map<string, int> sub_seq;

		for (int i = 0; i < s.size(); i += 1)
		{
			string &&sub = s.substr(i, 10);
			sub_seq[sub] += 1;
		}

		vector<string> res;
		for (auto &iter : sub_seq)
		{
			if (iter.second > 1)
			{
				res.push_back(iter.first);
			}
		}

		return res;
	}
};

int main()
{
	auto sol = new Solution();
	sol->print(sol->findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"));
}