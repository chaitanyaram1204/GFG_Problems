namespace std
{
    template <>
    struct hash<vector<int>>
    {
        size_t operator()(const vector<int> &v) const
        {
            hash<int> hasher;
            size_t seed = 0;
            for (int i : v)
            {
                seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
            return seed;
        }
    };
}

class Solution
{
public:
    void solve(vector<int> &arr, int n, int k, set<vector<int>> &ans, vector<int> &temp, int i)
    {
        if (k == 0)
        {
            ans.insert(temp);
            return;
        }
        if (k < 0 || i >= n)
            return;
        for (int j = i + 1; j < n; j++)
        {
            temp.push_back(arr[j]);
            solve(arr, n, k - arr[j], ans, temp, j);
            temp.pop_back();
        }
    }
    vector<vector<int>> CombinationSum2(vector<int> arr, int n, int k)
    {
        sort(arr.begin(), arr.end());
        set<vector<int>> ans;
        vector<int> temp;
        solve(arr, n, k, ans, temp, -1);
        vector<vector<int>> res;
        for (auto &i : ans)
        {
            res.push_back(i);
        }
        return res;
    }
};