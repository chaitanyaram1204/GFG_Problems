class Solution
{
public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &nusm)
    {
        long long maxProd = nusm[0], minProd = nusm[0], ans = nusm[0];
        for (int i = 1; i < nusm.size(); i++)
        {
            if (nusm[i] < 0)
            {
                swap(maxProd, minProd);
            }
            maxProd = max((long long)nusm[i], maxProd * nusm[i]);
            minProd = min((long long)nusm[i], minProd * nusm[i]);
            ans = max(ans, maxProd);
        }
        return ans;
    }
};