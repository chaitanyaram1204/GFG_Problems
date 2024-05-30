class Solution
{
public:
    int mod = 1e9 + 7;
    int solve(int ind1, int ind2, string s1, string s2, vector<vector<int>> &dp)
    {
        if (ind2 == s2.size())
        {
            //  cout<<ind1<<" "<<ind2<<endl;

            return 1;
        }
        if (ind1 >= s1.size())
        {
            return 0;
        }
        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        int ans = 0;
        // cout<<ind1<<" "<<ind2<<endl;
        if (s1[ind1] == s2[ind2])
        {
            ans = solve(ind1 + 1, ind2 + 1, s1, s2, dp);
        }
        ans += solve(ind1 + 1, ind2, s1, s2, dp);
        return dp[ind1][ind2] = ans % mod;
    }
    int countWays(string s1, string s2)
    {
        vector<int> prev(s2.size() + 1, 0);
        prev[s2.size()] = 1;

        for (int i = s1.size() - 1; i >= 0; i--)
        {
            for (int j = 0; j < s2.size(); j++)
            {
                if (s1[i] == s2[j])
                {
                    prev[j] = (prev[j + 1] + prev[j]) % mod;
                }
            }
        }

        return prev[0];
    }
};