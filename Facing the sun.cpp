class Solution
{
public:
    // Returns count buildings that can see sunlight
    int countBuildings(vector<int> &height)
    {
        int count = 0;
        int currMax = 0;

        for (int i : height)
        {
            if (i > currMax)
            {
                count += 1;
            }
            currMax = max(i, currMax);
        }

        return count;
    }
};