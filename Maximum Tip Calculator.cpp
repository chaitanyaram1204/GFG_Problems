class Solution
{
public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr)
    {
        vector<pair<int, int>> diff;
        for (int i = 0; i < n; i++)
        {
            diff.push_back({arr[i] - brr[i], i});
        }
        sort(diff.begin(), diff.end());

        long long totalsum = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            int index = diff[i].second;
            if (diff[i].first > 0 && x > 0)
            {
                totalsum += arr[index];
                x--;
            }
            else if (diff[i].first <= 0 && i + 1 > y)
            {
                totalsum += arr[index];
            }
            else
            {
                totalsum += brr[index];
            }
        }

        return totalsum;
    }
};