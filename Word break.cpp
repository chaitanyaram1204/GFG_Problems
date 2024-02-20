class Solution
{
public:
    int solve(int i, string &s, unordered_set<string> &se, vector<int> &dp)
    {
        if (i == s.size())
            return 1;
        if (dp[i] != -1)
            return dp[i];
        string temp;
        for (int j = i; j < s.size(); j++)
        {
            temp += s[j];
            if (se.find(temp) != se.end())
            {
                if (solve(j + 1, s, se, dp))
                {
                    return dp[i] = 1;
                }
            }
        }
        return dp[i] = 0;
    }
    int wordBreak(int n, string s, vector<string> &dictionary)
    {
        vector<int> dp(s.size(), -1);
        unordered_set<string> se;

        for (auto i : dictionary)
        {
            se.insert(i);
        }

        return solve(0, s, se, dp);
    }
};