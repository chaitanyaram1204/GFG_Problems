class Solution
{
public:
    /*You are required to complete this method */
    int atoi(string s)
    {
        int c = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
                ans = ans * 10 + s[i] - '0';
            else if (s[i] == '-' && i == 0)
            {
                c = 1;
                continue;
            }
            else
            {
                return -1;
            }
        }
        if (c == 1)
            ans = -ans;
        return ans;
    }
};