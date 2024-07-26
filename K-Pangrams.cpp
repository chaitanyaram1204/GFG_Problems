class Solution
{
public:
    bool kPangram(string str, int k)
    {
        vector<int> freq(26, 0);
        int cnt = 0;
        for (int i = 0; i < str.size(); i++)
        {
            char ch = str[i];
            if (ch == ' ')
                continue;
            freq[ch - 'a']++;
            if (freq[ch - 'a'] >= 2)
            {
                // cout << ch << endl;
                cnt += 1;
            }
        }

        int count = 0;
        for (auto it : freq)
        {
            if (it == 0)
                count++;
        }

        if (count != 0)
        {
            if (k < count || cnt < count)
            {
                return false;
            }
        }

        return true;
    }
};