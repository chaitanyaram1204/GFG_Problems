class Solution
{
public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr)
    {
        int i = 0;
        int n = arr.size();
        if (n == 1)
            return arr;
        while (i < n - 1)
        {
            int first = arr[i];
            int second = arr[i + 1];
            if (first == second)
            {
                arr[i] = arr[i] * 2;
                arr[i + 1] = 0;
                i += 1;
            }
            i++;
        }

        i = 0;
        int j = i + 1;
        while (j < n)
        {
            if (arr[i] == 0 && arr[j] != 0)
            {
                swap(arr[i], arr[j]);
                j++;
                i++;
            }
            else if (arr[i] == 0 && arr[j] == 0)
            {
                j++;
            }
            else
            {
                i++;
                j++;
            }
        }
        return arr;
    }
};