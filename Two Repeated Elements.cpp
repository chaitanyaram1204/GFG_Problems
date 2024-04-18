class Solution
{
public:
    // Function to find two repeated elements.
    vector<int> twoRepeated(int arr[], int n)
    {
        vector<int> ans;

        for (int i = 0; i < n + 2; i++)
        {
            int ele = abs(arr[i]);
            int id = ele - 1;
            if (arr[id] < 0)
                ans.push_back(ele);
            arr[id] = -arr[id];
        }
        return ans;
    }
};