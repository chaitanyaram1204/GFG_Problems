class Solution
{
public:
    void LIS(vector<int> &arr, vector<int> &dp)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[i] > arr[j] && arr[i] - arr[j] >= (i - j))
                {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }
    }
    int min_operations(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 1);
        LIS(nums, dp);
        return nums.size() - *max_element(dp.begin(), dp.end());
    }
};