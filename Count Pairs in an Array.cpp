class Solution
{
public:
    int countPairs(int arr[], int n)
    {
        vector<int> a;
        for (int i = 0; i < n; i++)
        {
            a.push_back(arr[i] * i);
        }
        vector<int> k;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int r = upper_bound(k.begin(), k.end(), a[i]) - k.begin();
            r = k.size() - r;
            ans += r;
            k.insert(upper_bound(k.begin(), k.end(), a[i]), a[i]);
        }
        return ans;
    }
};