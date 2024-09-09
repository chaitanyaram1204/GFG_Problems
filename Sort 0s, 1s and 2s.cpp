class Solution
{
public:
    void sort012(vector<int> &arr)
    {
        int low = 0;
        int high = arr.size() - 1;
        int mid = 0;

        while (mid <= high)
        {
            int value = arr[mid];
            if (value == 1)
            {
                mid++;
            }
            else if (value == 0)
            {
                swap(arr[mid], arr[low]);
                low++;
                mid++;
            }
            else
            {
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};