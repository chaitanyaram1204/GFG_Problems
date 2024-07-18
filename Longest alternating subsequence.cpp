class Solution
{
public:
    int alternatingMaxLength(vector<int> &arr)
    {

        int increasingSequence = 1;
        int decreasingSequence = 1;

        int n = arr.size();

        for (int i = 1; i < n; i++)
        {
            if (arr[i] > arr[i - 1])
            {
                increasingSequence = decreasingSequence + 1;
            }
            else if (arr[i] < arr[i - 1])
            {
                decreasingSequence = increasingSequence + 1;
            }
        }

        return max(increasingSequence, decreasingSequence);
    }
};