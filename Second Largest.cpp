class Solution
{
public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr)
    {
        // Code Here
        int maxi = -1;
        int second_maxi = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] > maxi)
            {
                second_maxi = maxi;
                maxi = arr[i];
            }
            else if (arr[i] > second_maxi && arr[i] != maxi)
            {
                second_maxi = arr[i];
            }
        }
        return second_maxi;
    }
};