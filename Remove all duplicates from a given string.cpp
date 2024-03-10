class Solution
{
public:
    string removeDuplicates(string str)
    {
        unordered_map<char, int> mp;
        string ans = "";
        for (int i = 0; i < str.size(); i++)
        {
            if (mp.find(str[i]) == mp.end())
            {
                ans += str[i];
            }
            mp[str[i]]++;
        }
        return ans;
    }
};