class Solution
{
public:
    vector<int> alternateSort(vector<int> &arr)
    {
        vector<int> temp(arr.size());
        sort(arr.begin(), arr.end());
        int j = 0;
        int n = arr.size() - 1;
        int k = 0;
        while (j < n)
        {
            temp[k++] = arr[n--];
            temp[k++] = arr[j++];
        }
        if (n == j)
        {
            temp[k] = arr[n];
        }
        return temp;
    }
};