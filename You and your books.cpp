class Solution
{
public:
    /*You are requried to complete this method */
    long long max_Books(int arr[], int n, int k)
    {
        long long ans = 0;
        long long maxi = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= k)
            {
                maxi += arr[i];
            }
            else
            {
                maxi = 0;
            }
            ans = max(maxi, ans);
        }
        return ans;
    }
};