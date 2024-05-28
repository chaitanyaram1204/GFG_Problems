class Solution
{
public:
    int solve(int ind, int weight, vector<int> &cost, vector<vector<int>> &dp)
    {
        if (weight == 0)
            return 0;
        if (ind >= cost.size() || weight < 0)
            return 1e8;
        if (dp[ind][weight] != -1)
            return dp[ind][weight];

        int take = 1e8;
        if (weight - (ind + 1) >= 0 && cost[ind] != -1)
        {
            take = cost[ind] + solve(ind, weight - (ind + 1), cost, dp);
        }
        int not_take = solve(ind + 1, weight, cost, dp);

        return dp[ind][weight] = min(take, not_take);
    }

    int minimumCost(int n, int w, vector<int> &cost)
    {
        vector<vector<int>> dp(n, vector<int>(w + 1, -1));
        int result = solve(0, w, cost, dp);
        return (result >= 1e9) ? -1 : result;
    }
};