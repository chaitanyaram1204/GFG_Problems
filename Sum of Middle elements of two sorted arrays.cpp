class Solution
{
public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2)
    {
        int i = 0;
        int j = 0;
        int n = arr1.size();
        int m = arr2.size();
        int sum = 0;
        int count = 0;

        while (i < n && j < m)
        {
            if (arr1[i] >= arr2[j])
            {
                j++;

                count++;

                if (count > n + 1)
                {
                    break;
                }

                if (count > n - 1)
                {
                    // cout << i << " " << j << count << endl;
                    sum += arr2[j - 1];
                }
            }
            else
            {
                i++;

                count++;

                if (count > n + 1)
                {
                    break;
                }

                if (count > n - 1)
                {
                    // cout << i << " " << j << count << endl;
                    sum += arr1[i - 1];
                }
            }
        }
        while (i < n)
        {
            i++;

            count++;

            if (count > n + 1)
            {
                break;
            }

            if (count > n - 1)
            {
                sum += arr1[i - 1];
            }
        }
        while (j < m)
        {
            count++;

            j++;

            if (count > n + 1)
            {
                break;
            }

            if (count > n - 1)
            {
                sum += arr2[j - 1];
            }
        }

        return sum;
    }
};