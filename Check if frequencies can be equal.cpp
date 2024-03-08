class Solution
{
public:
    bool sameFreq(string s)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }

        int mini = 1e9, maxi = -1e9;
        for (auto i : mp)
        {
            mini = min(mini, i.second);
            maxi = max(maxi, i.second);
        }

        if (maxi - mini > 1)
            return 0;
        else if (maxi == mini)
            return 1;
        else
        {
            int maxi_c = 0, mini_c = 0;
            for (auto i : mp)
            {
                if (i.second == maxi)
                    maxi_c++;
                if (i.second == mini)
                    mini_c++;
            }

            if (maxi_c == 1)
                return 1;
            return 0;
        }
    }
};