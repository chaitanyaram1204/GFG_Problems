class Solution
{
public:
    int maxDistance(vector<int> &arr)
    {
        map<int, int> mp;
        int mn = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]] = i;
        }
        for (int i = 0; i < arr.size(); i++)
        {
            if (mp.find(arr[i]) != mp.end())
            {
                int r = mp[arr[i]] - i;
                if (r > mn)
                {
                    mn = r;
                }
            }
        }
        return mn;
    }
};