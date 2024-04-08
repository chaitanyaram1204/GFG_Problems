class Solution
{
public:
    long long solve(vector<vector<long long>> &dp, int arr[], int i, int j)
    {

        if (i > j)
        {
            return 0;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        long long take = arr[i] + min(solve(dp, arr, i + 2, j), solve(dp, arr, i + 1, j - 1));
        long long notTake = arr[j] + min(solve(dp, arr, i + 1, j - 1), solve(dp, arr, i, j - 2));

        long long ans = max(take, notTake);
        return dp[i][j] = ans;
    }
    long long maximumAmount(int n, int arr[])
    {
        vector<vector<long long>> dp(n, vector<long long>(n, -1));
        return solve(dp, arr, 0, n - 1);
    }
};