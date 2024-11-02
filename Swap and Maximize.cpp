class Solution
{
public:
    long long maxSum(vector<int> &arr)
    {
        int n = arr.size();

        sort(arr.begin(), arr.end());
        vector<int> rearranged(2 * n);
        int left = 0;
        int right = n - 1;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                rearranged[i] = arr[right--];
            }
            else
            {
                rearranged[i] = arr[left++];
            }
        }
        int maxSum = 0;
        for (int i = 0; i < n; i++)
        {
            maxSum += abs(rearranged[i] - rearranged[(i + 1) % n]); // Circular difference
        }
        return maxSum;
    }
};