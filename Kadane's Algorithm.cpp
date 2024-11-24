class Solution
{
public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr)
    {
        // code here...
        int maxi = INT_MIN;
        int sum = 0;
        for (auto it : arr)
        {
            sum += it;
            maxi = max(maxi, sum);
            if (sum < 0)
                sum = 0;
        }
        return maxi;
    }
};