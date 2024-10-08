class Solution
{
public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr)
    {
        // code here...
        int kadane = INT_MIN, count = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            count += arr[i];
            kadane = max(kadane, count);
            if (count < 0)
                count = 0;
        }
        return kadane;
    }
};