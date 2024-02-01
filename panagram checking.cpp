class Solution
{
public:
    // Function to check if a string is Pangram or not.
    bool checkPangram(string s)
    {
        if (s.size() < 26)
            return false;
        unordered_map<char, int> mp;
        for (auto i : s)
        {
            if (isalpha(i))
                mp[tolower(i)]++;
        }
        return mp.size() == 26 ? true : false;
    }
};