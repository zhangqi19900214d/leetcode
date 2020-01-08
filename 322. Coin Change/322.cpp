/*
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Note:
You may assume that you have an infinite number of each kind of coin.
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
        if (amount <= 0 || coins.size() == 0)
        {
            return 0;
        }

        sort(coins.begin(), coins.end());
        if (coins[0] > amount)
        {
            return -1;
        }

        vector<int> dp(amount+1, 0);
        dp[0] = 0;
        dp[coins[0]] = 1;
        for (auto coin : coins)
        {
            if (coin <= amount)
            {
                dp[coin] = 1;
            }
        }

        for (int i = coins[0] + 1; i <= amount; i++)
        {
            for (auto coin : coins)
            {
                if (i - coin >= 0 && dp[i - coin] > 0)
                {
                    if (dp[i] <= 0)
                    {
                        dp[i] = dp[i - coin] + 1;
                    }
                    else
                    {
                        dp[i] = min(dp[i], dp[i - coin] + 1);
                    }
                }
            }
        }

        return dp[amount] > 0 ? dp[amount] : -1;
    }
};

int main()
{
    auto sol = new Solution();
    cout << sol->coinChange(vector<int>{1, 2, 5}, 11) << endl;
    cout << sol->coinChange(vector<int>{2}, 3) << endl;
    cout << sol->coinChange(vector<int>{1,2}, 2) << endl;
}
