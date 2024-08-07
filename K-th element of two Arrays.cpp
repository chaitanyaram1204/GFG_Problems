class Solution
{
public:
    int kthElement(int k, vector<int> &arr1, vector<int> &arr2)
    {
        int i = 0;
        int j = 0;
        int n = arr1.size();
        int m = arr2.size();
        while (i < n && j < m)
        {
            if (arr1[i] > arr2[j])
            {
                j++;
                k--;
                if (k == 0)
                {
                    return arr2[j - 1];
                }
            }
            else
            {
                i++;
                k--;
                if (k == 0)
                {
                    return arr1[i - 1];
                }
            }
        }
        while (i < n)
        {
            i++;
            k--;
            if (k == 0)
            {
                return arr1[i - 1];
            }
        }
        while (j < m)
        {
            j++;
            k--;
            if (k == 0)
            {
                return arr2[j - 1];
            }
        }
        return 0;
    }
};