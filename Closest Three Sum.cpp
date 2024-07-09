class Solution
{
public:
    int threeSumClosest(vector<int> arr, int target)
    {
        // Your code goes here
        int mini = INT_MAX;
        int ans = 0;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        for (int i = 0; i < n - 2; i++)
        {
            int j = i + 1;
            int k = n - 1;

            while (j < k)
            {
                int sum = arr[i] + arr[j] + arr[k];

                if (mini > abs(sum - target))
                {
                    mini = abs(sum - target);
                    ans = sum;
                }
                else if (mini == abs(sum - target))
                {
                    ans = max(sum, ans);
                }

                if (sum > target)
                    k--;
                else
                    j++;
            }
        }

        return ans;
    }
};