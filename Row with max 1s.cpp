class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> &arr)
    {
        int row = -1;
        int maxi = 0;
        int n = arr.size();
        int m = arr[0].size();
        for (int i = 0; i < n; i++)
        {
            int ans = 0;
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 1)
                {
                    ans += (m - j);
                    break;
                }
            }
            if (ans > maxi)
            {
                maxi = ans;
                row = i;
            }
        }
        return row;
    }
};