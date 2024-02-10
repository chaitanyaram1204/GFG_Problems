class Solution
{
public:
    int solve(int i, int j, int n, int k, vector<vector<int>> &arr, vector<vector<vector<int>>> &dp)
    {
        if (i == n - 1 && j == n - 1 && k == arr[i][j])
        {
            return 1;
        }
        if (k < 0 || i >= n || j >= n)
        {
            return 0;
        }
        if (dp[i][j][k] != -1)
            return dp[i][j][k];
        long long right = solve(i + 1, j, n, k - arr[i][j], arr, dp);
        long long down = solve(i, j + 1, n, k - arr[i][j], arr, dp);
        return dp[i][j][k] = right + down;
    }

    long long numberOfPath(int n, int k, vector<vector<int>> &arr)
    {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        return solve(0, 0, n, k, arr, dp);
    }
};