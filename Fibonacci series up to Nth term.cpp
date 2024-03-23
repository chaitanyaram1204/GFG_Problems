class Solution
{
public:
    int mod = 1e9 + 7;
    vector<int> Series(int n)
    {
        vector<int> ans;
        int f = 0;
        int g = 1;
        ans.push_back(f);
        ans.push_back(g);
        for (int i = 1; i < n; i++)
        {
            int h = (f % mod + g % mod) % mod;
            ans.push_back(h);
            f = g;
            g = h;
        }
        return ans;
    }
};