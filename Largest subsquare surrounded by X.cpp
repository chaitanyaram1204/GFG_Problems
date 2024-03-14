class Solution
{
public:
    int largestSubsquare(int n, vector<vector<char>> a)
    {
        // code here
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {0, 0}));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] == 'X')
                {
                    if (i == 0 && j == 0)
                    {
                        dp[i][j] = {1, 1};
                    }
                    else
                    {
                        if (j > 0)
                            dp[i][j].first = dp[i][j - 1].first + 1;
                        else
                            dp[i][j].first = 1;
                        if (i > 0)
                            dp[i][j].second = dp[i - 1][j].second + 1;
                        else
                            dp[i][j].second = 1;
                    }
                }
            }
        }
        int res = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                int side = min(dp[i][j].first, dp[i][j].second);
                while (side > res)
                {
                    if (dp[i][j - side + 1].second >= side && dp[i - side + 1][j].first >= side)
                    {
                        res = side;
                        break;
                    }
                    else
                    {
                        side--;
                    }
                }
            }
        }
        return res;
    }
};