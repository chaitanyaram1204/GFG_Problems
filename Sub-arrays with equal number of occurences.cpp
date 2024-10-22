class Solution
{
public:
    int sameOccurrence(vector<int> &nums, int x, int y)
    {
        unordered_map<int, int> mp;
        int xcount = 0, ycount = 0;
        int result = 0;
        mp[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == x)
                xcount++;
            else if (nums[i] == y)
                ycount++;
            int diff = xcount - ycount;
            if (mp.find(diff) != mp.end())
            {
                result += mp[diff];
            }
            mp[diff]++;
        }
        return result;
    }
};