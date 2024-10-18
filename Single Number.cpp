class Solution
{
public:
    int getSingle(vector<int> &nums)
    {
        int xorvalue = 0;
        for (auto it : nums)
            xorvalue ^= it;
        return xorvalue;
    }
};