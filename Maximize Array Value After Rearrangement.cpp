class Solution
{
public:
    int Maximize(vector<int> &nums)
    {
        int m = 1e9 + 7;
        long long result = 0;
        sort(nums.begin(), nums.end());
        for (long long i = 0; i < nums.size(); i++)
        {
            result = (result + (long long)(i * nums[i])) % m;
        }
        return (int)result;
    }
};