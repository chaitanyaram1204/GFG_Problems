class Solution
{
public:
    void pushZerosToEnd(vector<int> &arr)
    {

        int k = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] > 0)
            {
                int temp = arr[i];
                arr[i] = 0;
                arr[k++] = temp;
            }
        }
    }
};