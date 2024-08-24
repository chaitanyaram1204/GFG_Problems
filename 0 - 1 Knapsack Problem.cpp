class Solution
{
public:
    // Function to return max value that can be put in knapsack of capacity W.
    int solve(int i, int W, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp)
    {
        if (i == 0)
        {
            if (W >= wt[0])
                return val[i];
            return 0;
        }
        if (W == 0)
            return 0;

        if (dp[i][W] != -1)
            return dp[i][W];

        int pick = INT_MIN;
        if (W >= wt[i])
        {
            pick = val[i] + solve(i - 1, W - wt[i], wt, val, dp);
        }

        int not_pick = solve(i - 1, W, wt, val, dp);

        return dp[i][W] = max(pick, not_pick);
    }
    int knapSack(int W, vector<int> &wt, vector<int> &value)
    {
        vector<vector<int>> dp(wt.size() + 1, vector<int>(W + 1, 0));
        for (int w = wt[0]; w <= W; w++)
        {
            dp[0][w] = value[0];
        }

        for (int i = 1; i < wt.size(); i++)
        {
            for (int w = 1; w <= W; w++)
            {
                int pick = INT_MIN;
                if (w >= wt[i])
                {
                    pick = value[i] + dp[i - 1][w - wt[i]];
                }
                int not_pick = dp[i - 1][w];
                dp[i][w] = max(pick, not_pick);
            }
        }
        return dp[wt.size() - 1][W];
    }
};