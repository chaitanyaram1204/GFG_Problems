class Solution
{
public:
    /*You are required to complete this method*/
    int solve(int i, int j, string pattern, string s, vector<vector<int>> &dp)
    {
        if (i < 0 && j < 0)
            return 1;
        if (i < 0 && j >= 0)
            return 0;
        if (j < 0 && i >= 0)
        {
            for (int in = 0; in <= i; in++)
            {
                if (pattern[in] != '*')
                    return 0;
            }
            return 1;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        if (pattern[i] == s[j] || pattern[i] == '?')
        {
            return solve(i - 1, j - 1, pattern, s, dp);
        }
        if (pattern[i] == '*')
            return solve(i, j - 1, pattern, s, dp) || solve(i - 1, j, pattern, s, dp);
        return false;
    }
    int wildCard(string pattern, string s)
    {
        vector<vector<int>> dp(pattern.size() + 1, vector<int>(s.size() + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= pattern.size(); i++)
        {
            if (pattern[i - 1] == '*')
            {
                dp[i][0] = dp[i - 1][0] * 1;
            }
        }

        for (int i = 1; i <= pattern.size(); i++)
        {
            for (int j = 1; j <= s.size(); j++)
            {
                if (pattern[i - 1] == s[j - 1] || pattern[i - 1] == '?')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (pattern[i - 1] == '*')
                {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                else
                    dp[i][j] = 0;
            }
        }
        return dp[pattern.size()][s.size()];
    }
};