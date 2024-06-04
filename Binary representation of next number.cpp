class Solution
{
public:
    string binaryNextNumber(string s)
    {
        string result = "";
        bool flag = false;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == '0')
            {
                s[i] = '1';

                flag = true;
                break;
            }
            else
            {
                s[i] = '0';
            }
        }
        if (!flag)
            s = '1' + s;
        while (s[0] == '0' && s.size() > 1)
        {
            s.erase(s.begin());
        }
        return s;
        // cout<<s<<endl;
    }
};