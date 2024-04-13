class Solution
{
public:
    long long reversedBits(long long x)
    {
        long long num = 0;
        for (int i = 0; i < 32; i++)
        {
            long long bit = (x & (1 << i)) > 0 ? 1 : 0;
            num = num + (bit << (31 - i));
        }
        return num;
    }
};