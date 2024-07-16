class Solution
{
public:
    string printString(string s, char ch, int count)
    {
        int cnt = 1, i = 0;
        int n = s.size();

        while (i < n && cnt <= count)
        {
            char character = s[i];
            if (ch == character)
            {
                cnt++;
            }
            i++;
        }

        string ans = "";
        ans += s.substr(i);

        return ans;
    }
};