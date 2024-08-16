class Solution
{
public:
    // Function to find the maximum number of cuts.
    int solve(int n, int x, int y, int z, vector<int> &dp)
    {
        if (n < 0)
        {
            return INT_MIN;
        }
        if (n == 0)
        {
            return 0;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        return dp[n] = 1 + max(solve(n - x, x, y, z, dp), max(solve(n - y, x, y, z, dp), solve(n - z, x, y, z, dp)));
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        // int value = solve(n,x,y,z,dp);
        // if(value <= 0){
        //     return 0;
        // }
        for (int i = 1; i <= n; i++)
        {
            if (i - x >= 0 && dp[i - x] != -1)
            {
                dp[i] = max(dp[i], 1 + dp[i - x]);
            }
            if (i - y >= 0 && dp[i - y] != -1)
            {
                dp[i] = max(dp[i], 1 + dp[i - y]);
            }
            if (i - z >= 0 && dp[i - z] != -1)
                dp[i] = max(dp[i], 1 + dp[i - z]);
        }
        return dp[n] == -1 ? 0 : dp[n];
    }
};