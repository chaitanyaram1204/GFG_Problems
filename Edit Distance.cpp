class Solution
{
public:
    int solve(int i, int j, string s1, string s2, vector<vector<int>> &dp)
    {
        if (j < 0)
            return (i + 1);
        if (i < 0)
            return (j + 1);
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if (s1[i] == s2[j])
        {
            return dp[i][j] = solve(i - 1, j - 1, s1, s2, dp);
        }
        return dp[i][j] = 1 + min(solve(i - 1, j, s1, s2, dp), min(solve(i - 1, j - 1, s1, s2, dp), solve(i, j - 1, s1, s2, dp)));
        // delete in first string // replace in first string  //insert in first string
    }
    int editDistance(string str1, string str2)
    {
        vector<vector<int>> dp(str1.size(), vector<int>(str2.size(), -1));
        return solve(str1.size() - 1, str2.size() - 1, str1, str2, dp);
    }
};