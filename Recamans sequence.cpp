class Solution
{
public:
    vector<int> recamanSequence(int n)
    {
        // code here
        unordered_map<int, int> mp;
        vector<int> dp(n, 0);
        dp[0] = 0;
        mp[0]++;
        for (int i = 1; i < n; i++)
        {
            int num = dp[i - 1] - i;
            if (num >= 0 and mp.find(num) == mp.end())
            {
                dp[i] = dp[i - 1] - i;
                mp[num] = 1;
            }
            else
            {
                dp[i] = dp[i - 1] + i;
                mp[dp[i - 1] + i] = 1;
            }
        }
        return dp;
    }
};
