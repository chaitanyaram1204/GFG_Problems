class Solution
{
public:
    bool check(int n)
    {
        while (n > 0)
        {
            int r = n % 10;
            if (r == 4)
                return 1;
            n /= 10;
        }
        return 0;
    }
    int countNumberswith4(int n)
    {
        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            if (check(i))
                count++;
        }
        return count;
    }
};