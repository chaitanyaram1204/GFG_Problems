class Solution
{
public:
    void rearrange(vector<int> &arr)
    {
        vector<int> negative;
        vector<int> positive;
        int n = arr.size();
        for (auto it : arr)
        {
            if (it >= 0)
            {
                positive.push_back(it);
            }
            else
            {
                negative.push_back(it);
            }
        }
        bool flag = false;
        int j = 0;
        int k = 0;
        int x = positive.size();
        int y = negative.size();
        int i;
        for (i = 0; i < n && j < x && k < y; i++, j++, k++)
        {
            arr[i++] = (positive[j]);
            arr[i] = (negative[k]);
        }

        while (j < x)
        {
            arr[i++] = positive[j++];
        }
        while (k < y)
            arr[i++] = negative[k++];
    }
};