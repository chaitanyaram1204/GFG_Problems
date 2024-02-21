class Solution
{
public:
    int mod = 1003;
    int solve(int i, int j, int isTrue, string &s, vector<vector<vector<int>>> &dp)
    {
        if (i > j)
            return 0;

        if (i == j)
        {
            if (isTrue)
            {
                return s[i] == 'T';
            }
            else
            {
                return s[i] == 'F';
            }
        }

        if (dp[i][j][isTrue] != -1)
            return dp[i][j][isTrue];

        int ways = 0;

        for (int k = i + 1; k < j; k++)
        {
            int leftT, leftF, rightT, rightF;
            if (dp[i][k - 1][1] == -1)
                leftT = solve(i, k - 1, 1, s, dp) % mod;
            else
                leftT = dp[i][k - 1][1];

            if (dp[i][k - 1][0] == -1)
                leftF = solve(i, k - 1, 0, s, dp) % mod;
            else
                leftF = dp[i][k - 1][0];

            if (dp[k + 1][j][1] == -1)
                rightT = solve(k + 1, j, 1, s, dp) % mod;
            else
                rightT = dp[k + 1][j][1];

            if (dp[k + 1][j][0] == -1)
                rightF = solve(k + 1, j, 0, s, dp) % mod;
            else
                rightF = dp[k + 1][j][0];

            if (s[k] == '&')
            {
                if (isTrue)
                {
                    ways = (ways + leftT * rightT % mod) % mod;
                }
                else
                {
                    ways = (ways + leftT * rightF % mod + leftF * rightF % mod + leftF * rightT % mod) % mod;
                }
            }

            else if (s[k] == '|')
            {
                if (isTrue)
                {
                    ways = (ways + leftT * rightF % mod + leftT * rightT % mod + leftF * rightT % mod) % mod;
                }
                else
                {
                    ways = (ways + leftF * rightF % mod) % mod;
                }
            }
            else
            {
                if (isTrue)
                {
                    ways = (ways + leftF * rightT % mod + leftT * rightF % mod) % mod;
                }
                else
                {
                    ways = (ways + leftF * rightF % mod + leftT * rightT % mod) % mod;
                }
            }
        }
        return dp[i][j][isTrue] = ways;
    }
    int countWays(int n, string s)
    {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return solve(0, n - 1, 1, s, dp);
    }
};