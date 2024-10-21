class Solution
{
public:
    int countgroup(vector<int> &nums)
    {
        // Complete the function
        int xorvalue = 0;
        int n = nums.size();
        for (auto it : nums)
        {
            xorvalue ^= it;
        }
        if (xorvalue)
            return 0;

        const int MOD = 1e9 + 7;
        long long result = (1LL << (n - 1)) - 1; // Using bit shifting for power of 2
        result %= MOD;
        return (int)result;
    }
};