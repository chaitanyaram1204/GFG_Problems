
class Solution
{
public:
    int longestSubseq(int n, vector<int> &a)
    {
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++)
        {
            int maxi = 0;
            for (int j = 0; j < i; j++)
            {
                if (abs(a[i] - a[j]) == 1)
                {
                    maxi = max(maxi, 1 + dp[j]);
                }
            }
            dp[i] = max(dp[i], maxi);
        }
        return *max_element(dp.begin(), dp.end());
    }
};