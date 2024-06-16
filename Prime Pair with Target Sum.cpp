class Solution
{
public:
    vector<bool> getFirstNPrimes(int n)
    {
        vector<bool> prime(n + 1, true);
        for (int p = 2; p * p <= n; p++)
        {
            if (prime[p])
            {
                for (int i = p * p; i <= n; i += p)
                {
                    prime[i] = false;
                }
            }
        }
        return prime;
    }
    vector<int> getPrimes(int n)
    {
        if (n <= 3)
            return {-1, -1};
        vector<bool> primes = getFirstNPrimes(n);
        primes[0] = primes[1] = false;
        for (int i = 2; i < primes.size(); i++)
        {
            if (primes[i] && primes[n - i])
                return {i, n - i};
        }
        return {-1, -1};
    }
};