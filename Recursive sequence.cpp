class Solution
{
public:
    long long mod = 1e9 + 7;
    long long sequence(int n)
    {
        long long ans = 0;
        int j = 1;
        for (int i = 1; i <= n; i++)
        {
            long long temp = 1;
            for (int k = 0; k < i; k++)
            {
                temp = (temp * j) % mod;
                j++;
            }
            ans = (ans + temp) % mod;
        }
        return ans % mod;
    }
};