class Solution
{
public:
    long long countPairs(vector<int> &arr, vector<int> &brr)
    {
        int n = arr.size(), m = brr.size();
        vector<double> a(n), b(m);

        for (int i = 0; i < n; i++)
        {
            a[i] = log2(arr[i]) / arr[i];
        }

        for (int i = 0; i < m; i++)
        {
            b[i] = log2(brr[i]) / brr[i];
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        // log(x)/x > log(y)/y

        long long ans = 0;

        for (int i = 0; i < m; i++)
        {
            int ind = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
            if (ind != n)
                ans += (n - ind);
        }

        return ans;
    }
};