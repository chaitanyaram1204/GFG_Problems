class Solution
{
public:
    string smallestNumber(int s, int d)
    {
        string ans = "";

        if (9 * d < s)
            return "-1";

        while (s > 0)
        {
            // cout << " s " << s << " d " << d << " ans " << ans << endl;
            if (s > 9)
            {
                ans += "9";
                s -= 9;
                d -= 1;
            }
            else
            {
                if (d == 1)
                    ans += to_string(s);
                else
                {
                    ans += to_string(s - 1);
                    for (int i = 0; i < d - 2; i++)
                    {
                        ans += "0";
                    }
                    ans += "1";
                }

                break;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};