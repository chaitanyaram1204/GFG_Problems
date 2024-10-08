class Solution
{
public:
    int pairsum(vector<int> &arr)
    {
        // code here
        sort(arr.begin(), arr.end());
        return arr[arr.size() - 2] + arr[arr.size() - 1];
    }
};