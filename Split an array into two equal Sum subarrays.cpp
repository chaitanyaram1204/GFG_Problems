class Solution
{
public:
    bool canSplit(vector<int> &arr)
    {
        int totalsum = accumulate(arr.begin(), arr.end(), 0);
        int currentsum = 0;
        if (totalsum % 2)
            return false;
        for (auto it : arr)
        {
            currentsum += it;
            if (currentsum == totalsum / 2)
                break;
            if (currentsum > totalsum / 2)
                return false;
        }
        return true;
    }
};