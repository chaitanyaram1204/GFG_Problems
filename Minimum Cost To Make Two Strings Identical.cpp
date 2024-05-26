class Solution
{
public:
    int solve(int ind1, int ind2, const string &x, const string &y, int costX, int costY, vector<vector<int>> &dp)
    {
        if (dp[ind1][ind2] != -1)
        {
            return dp[ind1][ind2];
        }

        if (ind1 == x.size())
        {
            return (y.size() - ind2) * costY;
        }

        if (ind2 == y.size())
        {
            return (x.size() - ind1) * costX;
        }

        if (x[ind1] == y[ind2])
        {
            dp[ind1][ind2] = solve(ind1 + 1, ind2 + 1, x, y, costX, costY, dp);
        }
        else
        {
            int insertCost = solve(ind1, ind2 + 1, x, y, costX, costY, dp) + costY;
            int deleteCost = solve(ind1 + 1, ind2, x, y, costX, costY, dp) + costX;
            dp[ind1][ind2] = min(insertCost, deleteCost);
        }

        return dp[ind1][ind2];
    }

    int findMinCost(string x, string y, int costX, int costY)
    {
        int m = x.size();
        int n = y.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve(0, 0, x, y, costX, costY, dp);
    }
};