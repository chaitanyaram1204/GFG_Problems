class Solution
{
public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int> &arr)
    {
        // Your code goes here.
        int first = INT_MIN;
        int second = INT_MIN;
        int c1 = 0;
        int c2 = 0;

        for (auto number : arr)
        {
            if (number == first)
                c1++;
            else if (number == second)
                c2++;
            else if (c1 == 0)
            {
                c1++;
                first = number;
            }
            else if (c2 == 0)
            {
                c2++;
                second = number;
            }
            else
            {
                c1--;
                c2--;
            }
        }

        c1 = 0;
        c2 = 0;
        for (auto number : arr)
        {
            if (number == first)
                c1++;
            else if (number == second)
                c2++;
        }

        vector<int> result;

        int n = arr.size();
        if (c1 > n / 3)
            result.push_back(first);
        if (c2 > n / 3)
            result.push_back(second);
        sort(result.begin(), result.end());
        return result;
    }
};