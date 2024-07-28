class Solution
{
public:
    string removeDups(string str)
    {
        string ans = "";
        vector<int> freq(26, 0);
        for (auto ch : str)
        {
            if (freq[ch - 'a'] >= 1)
                continue;
            freq[ch - 'a']++;
            ans += ch;
        }
        return ans;
    }
};