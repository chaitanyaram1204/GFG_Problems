class Solution
{
public:
    int solve(int i, int j, int k, string &A, string &B, string &C, vector<vector<vector<int>>> &dp)
    {
        if (i < 0 || j < 0 || k < 0)
        {
            return 0;
        }
        if (dp[i][j][k] != -1)
            return dp[i][j][k];

        if (A[i] == B[j] && B[j] == C[k])
        {

            return dp[i][j][k] = 1 + solve(i - 1, j - 1, k - 1, A, B, C, dp);
        }

        return dp[i][j][k] = max({solve(i - 1, j, k, A, B, C, dp),
                                  solve(i, j - 1, k, A, B, C, dp),
                                  solve(i, j, k - 1, A, B, C, dp),
                                  solve(i - 1, j - 1, k, A, B, C, dp),
                                  solve(i - 1, j, k - 1, A, B, C, dp),
                                  solve(i, j - 1, k - 1, A, B, C, dp)});
    }

    int LCSof3(string A, string B, string C, int n1, int n2, int n3)
    {
        vector<vector<vector<int>>> dp(n1 + 1, vector<vector<int>>(n2 + 1, vector<int>(n3 + 1, -1)));
        return solve(n1 - 1, n2 - 1, n3 - 1, A, B, C, dp);
    }
};