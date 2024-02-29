class Solution
{
public:
    int peakElement(int arr[], int n)
    {
        int low = 0;
        int high = n - 1;
        while (low < high)
        {
            int mid = (low + high) / 2;

            if (arr[mid] >= arr[mid - 1])
            {
                if (arr[mid] >= arr[mid + 1])
                {
                    return mid;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
};