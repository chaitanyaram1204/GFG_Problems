class Solution
{
public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int> &arr, int target)
    {
        int count = 0;
        int sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (auto it : arr)
        {
            sum += it;
            if (mp.count(sum - target))
            {
                count += mp[(sum - target)];
            }
            mp[sum]++;
        }
        return count;
    }
};