class Solution
{
public:
    int findPeakElement(vector<int> &arr)
    {
        int x = arr[0];
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] < arr[i - 1])
                break;
            x = max(x, arr[i]);
        }
        return x;
    }
};