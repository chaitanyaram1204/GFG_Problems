class Solution
{
public:
    void matchPairs(int n, char nuts[], char bolts[])
    {
        vector<char> temp = {'!', '#', '$', '%', '&', '*', '?', '@', '^'};
        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nuts[i]]++;
        }

        int j = 0;
        for (int i = 0; i < temp.size(); i++)
        {
            while (mp[temp[i]]--)
            {
                nuts[j] = temp[i];
                bolts[j] = temp[i];
                j++;
            }
        }
    }
};