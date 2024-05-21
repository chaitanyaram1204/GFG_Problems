class Solution
{
public:
    vector<int> printKClosest(vector<int> arr, int n, int K, int x)
    {
        vector<int> ans;
        int i = -1;
        int j = -1;
        for (int k = 0; k < n; k++)
        {
            if (arr[k] > x)
            {
                i = k - 1;
                j = k;
                break;
            }
            if (arr[k] == x)
            {
                i = k - 1;
                j = k + 1;
                break;
            }
        }
        if (i == -1 && j == -1)
        {
            for (int k = n - 1; k >= 0; k--)
            {
                ans.push_back(arr[k]);
                if (ans.size() == K)
                    return ans;
            }
        }
        int cnt = 0;
        while (i >= 0 && j < n)
        {
            if (ans.size() == K)
                break;
            if (abs(arr[i] - x) < abs(arr[j] - x))
            {
                ans.push_back(arr[i]);
                i--;
                continue;
            }
            if (abs(arr[i] - x) > abs(arr[j] - x))
            {
                ans.push_back(arr[j]);
                j++;
                continue;
            }
            if (abs(arr[i] - x) == abs(arr[j] - x))
            {
                ans.push_back(max(arr[i], arr[j]));
                if (arr[i] >= arr[j])
                    i--;
                else
                    j++;
                continue;
            }
        }
        if (ans.size() == K)
            return ans;
        while (i >= 0 && ans.size() != K)
        {
            ans.push_back(arr[i]);
            i--;
        }
        while (j < n && ans.size() != K)
        {
            ans.push_back(arr[j]);
            j++;
        }

        return ans;
    }
};