class Solution
{
public:
    int swapNibbles(int n)
    {
        return (n >> 4 | (n & 15) << 4);
    }
};