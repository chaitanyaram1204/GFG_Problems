class Solution
{
public:
    int minIncrements(vector<int> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int ans = 0;
        int curr = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (curr >= arr[i])
            {
                ans += (curr + 1 - arr[i]);
                curr = curr + 1;
            }
            else
            {
                curr = arr[i];
            }
        }
        return ans;
    }
};