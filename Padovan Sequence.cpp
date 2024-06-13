class Solution
{
public:
    int mod = 1e9 + 7;
    int padovanSequence(int n)
    {
        if (n <= 2)
            return 1;
        int prev = 1;
        int secondprev = 1;
        int thirdprev = 1;
        for (int i = 3; i <= n; i++)
        {
            int curr = (secondprev + thirdprev) % mod;
            thirdprev = secondprev;
            secondprev = prev;
            prev = curr;
        }
        return prev;
    }
};