class Solution
{
public:
    vector<int> find3Numbers(vector<int> &arr)
    {
        int n = arr.size();
        if (n < 3)
            return {};
        vector<int> leftMin(n), rightMax(n);

        leftMin[0] = arr[0];
        rightMax[n - 1] = arr[n - 1];

        for (int i = 1; i < n; i++)
        {
            leftMin[i] = min(arr[i], leftMin[i - 1]);
            rightMax[n - i - 1] = max(arr[n - i - 1], rightMax[n - i]);
        }

        for (int i = 1; i < n - 1; i++)
        {
            if (leftMin[i] < arr[i] && arr[i] < rightMax[i])
            {
                return {leftMin[i], arr[i], rightMax[i]};
            }
        }
        return {};
    }
};