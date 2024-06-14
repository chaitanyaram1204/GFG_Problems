class Solution
{
public:
    string armstrongNumber(int n)
    {
        int number = n;
        int sum = 0;
        while (n > 0)
        {
            int r = n % 10;
            sum += pow(r, 3);
            n /= 10;
        }
        if (number == sum)
            return "true";
        return "false";
    }
};