class Solution
{
public:
    vector<vector<int>> findTriplets(vector<int> &arr)
    {
        // Code here
        int n = arr.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]].push_back(i);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < n - 2; i++)
        {
            int first = arr[i], firstInd = i;
            for (int j = i + 1; j < n; j++)
            {
                int second = arr[j], secondInd = j;
                int third = -(first + second);
                if (mp.find(third) != mp.end())
                {
                    for (auto it : mp[third])
                    {
                        if (it > j)
                            ans.push_back({firstInd, secondInd, it});
                    }
                }
            }
        }

        return ans;
    }
};