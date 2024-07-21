class Solution
{
public:
    int mod = 1e9 + 7;
    long long int findMaxProduct(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 1)
            return arr[0];
        long long int produ = 1;
        int negativeCount = 0;
        int maxNegative = INT_MIN;
        int zero = 0;
        for (auto i : arr)
        {
            if (i < 0)
            {
                negativeCount++;
                maxNegative = max(maxNegative, i);
            }
            else if (i == 0)
            {
                zero++;
                continue;
            }
            produ = (produ * i) % mod;
        }
        if (zero == n)
            return 0;
        if (zero + negativeCount == n && negativeCount == 1)
            return 0;
        if (negativeCount % 2 != 0)
        {
            produ /= maxNegative;
            produ = (produ + mod) % mod;
        }

        return produ;
    }
};