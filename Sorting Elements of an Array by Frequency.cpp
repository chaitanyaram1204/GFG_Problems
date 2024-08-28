class Solution
{
public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int> &arr)
    {
        map<int, int> mp;
        for (auto it : arr)
        {
            mp[it]++;
        }
        vector<pair<int, int>> result;
        for (auto it : mp)
        {
            result.push_back({it.second, it.first});
        }
        sort(result.begin(), result.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             {
                 if (a.first == b.first)
                 {
                     return a.second < b.second; // sort by value ascending if frequencies are equal
                 }
                 return a.first > b.first; // sort by frequency descending
             });
        vector<int> sorted;
        int i;
        for (i = 0; i < result.size() - 1; i++)
        {
            if (result[i].first == result[i + 1].first)
            {
                if (result[i].second > result[i + 1].second)
                {
                    for (int j = 0; j < result[i].first; j++)
                    {
                        sorted.push_back(result[i + 1].second);
                    }
                    for (int j = 0; j < result[i].first; j++)
                    {
                        sorted.push_back(result[i].second);
                    }
                }
                else
                {
                    for (int j = 0; j < result[i].first; j++)
                    {
                        sorted.push_back(result[i].second);
                    }
                    for (int j = 0; j < result[i].first; j++)
                    {
                        sorted.push_back(result[i + 1].second);
                    }
                }
                i += 1;
            }
            else
            {
                for (int j = 0; j < result[i].first; j++)
                {
                    sorted.push_back(result[i].second);
                }
            }
        }
        if (sorted.size() == arr.size())
            return sorted;
        for (int j = 0; j < result[result.size() - 1].first; j++)
        {
            sorted.push_back(result[result.size() - 1].second);
        }
        return sorted;
    }
};