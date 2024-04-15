class Solution
{
public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q)
    {
        int maxi = INT_MIN;
        for (int i = 0; i < b.size(); i++)
        {
            maxi = max(maxi, max(a[i], b[i]));
        }

        vector<int> arr(maxi + 1, 0);
        for (int i = 0; i < b.size(); i++)
        {
            arr[b[i]]++;
        }

        for (int i = 1; i <= maxi; i++)
        {
            arr[i] += arr[i - 1];
        }

        vector<int> ans;
        for (int i = 0; i < query.size(); i++)
        {
            ans.push_back(arr[a[query[i]]]);
        }

        return ans;
    }
};