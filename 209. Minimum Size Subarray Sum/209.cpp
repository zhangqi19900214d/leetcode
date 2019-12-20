/*
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ¡Ý s. If there isn't one, return 0 instead.

Example:

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }

        int left = 0;
        int right = 1;
        int sum = nums[0];
        int step = INT_MAX;
        if (sum >= s)
        {
            return 1;
        }

        while (right < nums.size())
        {
            sum += nums[right];
           // cout << sum << endl;
            while (sum >= s && left <= right)
            {
                if (sum >= s)
                {
                    step = min(right - left+1, step);
                }
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return step == INT_MAX ? 0 : step;
    }
};

int main()
{
    auto sol = new Solution();
    cout << sol->minSubArrayLen(7, vector<int>{2,3,1,2,4,3}) << endl;
    cout << sol->minSubArrayLen(15, vector<int>{1, 2, 3, 4, 5}) << endl;
}