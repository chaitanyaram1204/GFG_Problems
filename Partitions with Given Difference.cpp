class Solution
{
public:
    int countPartitions(int n, int d, vector<int> &arr)
    {
        // Code here
        int mod = 1e9 + 7;
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if ((sum + d) % 2 != 0)
        {
            return 0;
        }
        int target = (sum + d) / 2;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = target; j >= arr[i]; j--)
            {
                dp[j] = (dp[j] + dp[j - arr[i]]) % mod;
            }
        }
        return dp[target];
    }
};