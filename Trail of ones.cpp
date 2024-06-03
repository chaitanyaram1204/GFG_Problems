class Solution
{
public:
    int mod = 1e9 + 7;
    long long int solve(int n)
    {
        long long int a = 1;
        long long int b = 1;
        long long int c = (a + b);
        for (int i = 2; i <= n; i++)
        {
            b = a;
            a = c;
            c = (a + b) % mod;
        }
        return c;
    }
    long long int poww(int n)
    {
        long long int res = 1;
        while (n > 0)
        {
            res = (res * 2) % mod;
            n--;
        }
        return res;
    }
    int numberOfConsecutiveOnes(int n)
    {

        long long int noOnes = solve(n);
        return (poww(n) - noOnes + mod) % mod;
    }
};