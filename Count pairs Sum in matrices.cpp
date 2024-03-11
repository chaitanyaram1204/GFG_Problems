class Solution
{
public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
    {
        int col1 = 0, col2 = n - 1;
        int row1 = 0, row2 = n - 1;
        int count = 0;
        while (col1 < n && col2 >= 0)
        {
            int sum = mat1[col1][row1] + mat2[col2][row2];
            if (sum > x)
            {
                row2--;
            }
            else if (sum < x)
            {
                row1++;
            }
            else
            {
                count++;
                row1++;
                row2--;
            }
            if (row1 == n)
            {
                row1 = 0;
                col1++;
            }
            if (row2 == -1)
            {
                row2 = n - 1;
                col2--;
            }
        }
        return count;
    }
};