class Solution
{

public:
    int solve(int n, int m, int a[], int b[], vector<vector<int>> &dp)
    {
        if (m < 0)
            return 0;
        if (n == 0 && m > 0)
            return INT_MIN;
        if (n == 0 && m == 0)
            return a[n] * b[n];
        if (dp[n][m] != -1)
            return dp[n][m];

        int np = 0 + solve(n - 1, m, a, b, dp);
        int p = a[n] * b[m] + solve(n - 1, m - 1, a, b, dp);
        return dp[n][m] = max(np, p);
    }
    int maxDotProduct(int n, int m, int a[], int b[])
    {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(n - 1, m - 1, a, b, dp);
    }
};