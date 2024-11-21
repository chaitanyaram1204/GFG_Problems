class Solution
{
public:
    int solve(int ind, int n, vector<vector<int>> &dp, int buy, vector<int> &prices)
    {
        if (ind == n)
        {
            return 0;
        }

        if (dp[ind][buy] != -1)
        {
            return dp[ind][buy];
        }
        if (buy)
        {
            int pick = -prices[ind] + solve(ind + 1, n, dp, 0, prices);
            int not_pick = solve(ind + 1, n, dp, 1, prices);
            return dp[ind][buy] = max(pick, not_pick);
        }
        else
        {
            int pick = prices[ind] + solve(ind + 1, n, dp, 1, prices);
            int not_pick = solve(ind + 1, n, dp, 0, prices);
            return dp[ind][buy] = max(pick, not_pick);
        }
    }
    int maximumProfit(vector<int> &prices)
    {
        // code here
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, n, dp, 1, prices);
    }
};