class Solution
{
public:
    void nextPermutation(vector<int> &arr)
    {
        int n = arr.size() - 1;
        bool flag = false;
        while (n > 0)
        {
            if (arr[n] > arr[n - 1])
            {
                flag = true;
                n--;
                break;
            }
            n--;
        }
        if (!flag)
        {
            sort(arr.begin(), arr.end());
            return;
        }

        int j = arr.size() - 1;
        while (j > 0)
        {
            if (arr[j] > arr[n])
            {
                swap(arr[j], arr[n]);
                break;
            }
            j--;
        }
        sort(arr.begin() + n + 1, arr.end());
    }
};