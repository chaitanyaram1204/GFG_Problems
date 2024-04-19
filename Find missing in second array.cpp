class Solution
{

public:
    vector<int> findMissing(int a[], int b[], int n, int m)
    {
        map<int, int> mpp;
        vector<int> res;
        for (int i = 0; i < m; i++)
        {
            mpp[b[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (mpp[a[i]] == 0)
            {
                res.push_back(a[i]);
            }
        }
        return res;
    }
};