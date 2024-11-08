class Solution
{
public:
    int minRepeats(string &s1, string &s2)
    {
        int count = 0;
        string ns;
        while (ns.length() < s2.length() + s1.length())
        {
            ns = ns + s1;
            count++;
            if (ns.find(s2) != string::npos)
            {
                return count;
            }
        }
        return -1;
    }
};