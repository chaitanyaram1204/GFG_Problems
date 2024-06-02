class Solution
{
public:
    vector<int> constructList(int q, vector<vector<int>> &queries)
    {
        vector<int> ans;
        ans.push_back(0);
        int sum = 0;
        for (int i = q - 1; i >= 0; i--)
        {
            int first = queries[i][0];
            int second = queries[i][1];

            if (first == 0)
            {
                second ^= sum;
                ans.push_back(second);
            }
            else
            {
                sum ^= second;
            }
        }
        ans[0] ^= sum;
        sort(ans.begin(), ans.end());
        return ans;
    }
};