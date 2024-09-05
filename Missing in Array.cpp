class Solution
{
public:
    // Note that the size of the array is n-1
    int missingNumber(int n, vector<int> &arr)
    {

        int missing = 0;
        for (int i = 1; i <= n - 1; i++)
        {
            missing ^= arr[i - 1];
            missing ^= (i);
            // cout << missing << endl;
        }
        missing ^= n;
        return missing;
    }
};