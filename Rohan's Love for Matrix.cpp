class Solution
{
public:
    int firstElement(int n)
    {
        int mod = 1000000007, a = 1, b = 1, c = a + b, i = 1;
        while (i < n)
        {
            a = b;
            b = c;
            c = (a % mod + b % mod) % mod;
            i++;
        }
        return a;
    }
};