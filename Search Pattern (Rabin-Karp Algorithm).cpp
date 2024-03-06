class Solution
{
public:
    vector<int> search(string pattern, string text)
    {
        vector<int> vec;

        int len = pattern.length();

        for (int i = 0; i + len <= text.length(); ++i)
        {
            if (text.substr(i, len) == pattern)
            {
                vec.push_back(i + 1);
            }
        }

        return vec;
    }
};