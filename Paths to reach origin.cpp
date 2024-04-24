class Solution
{
public:
    int ways(int x, int y)
    {
        int mod = 1e9 + 7;
        vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));
        for (int i = 0; i <= x; i++)
        {
            for (int j = 0; j <= y; j++)
            {
                if (i == 0 && j == 0)
                    dp[i][j] = 1;
                else if (i == 0)
                    dp[i][j] = dp[i][j - 1];
                else if (j == 0)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
            }
        }
        return dp[x][y];
    }
};