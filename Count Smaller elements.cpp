class Solution
{
public:
    void merge(vector<int> &ans, vector<pair<int, int>> &nums, int left, int mid, int right)
    {
        vector<pair<int, int>> temp(right - left + 1);

        int i = left, j = mid + 1;
        int k = 0;

        while (i <= mid && j <= right)
        {
            if (nums[i].first <= nums[j].first)
            {
                temp[k++] = nums[j++];
            }
            else
            {
                ans[nums[i].second] += right - j + 1;
                temp[k++] = nums[i++];
            }
        }

        while (i <= mid)
            temp[k++] = nums[i++];
        while (j <= right)
            temp[k++] = nums[j++];

        for (int i = left; i <= right; i++)
        {
            nums[i] = temp[i - left];
        }
    }
    void mergesort(vector<int> &ans, vector<pair<int, int>> &nums, int low, int high)
    {
        if (low < high)
        {
            int mid = low + (high - low) / 2;
            mergesort(ans, nums, low, mid);
            mergesort(ans, nums, mid + 1, high);
            merge(ans, nums, low, mid, high);
        }
    }
    vector<int> constructLowerArray(vector<int> &arr)
    {
        int n = arr.size();

        vector<int> ans(n, 0);
        vector<pair<int, int>> nums;

        for (int i = 0; i < n; i++)
        {
            nums.push_back({arr[i], i});
        }

        mergesort(ans, nums, 0, n - 1);

        return ans;
    }
};