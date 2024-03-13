class Solution
{
public:
    vector<int> matrixDiagonally(vector<vector<int>> &mat)
    {
        vector<int> ans;
        int row = 0, col = 0;
        int n = mat.size();
        while (ans.size() == n * n)
        {
            /*Going diagonally upward direction*/
            while (row >= 0 && col < n)
            {
                if (row >= 0 && col < n && row < n && col >= 0)
                {
                    ans.push_back(mat[row][col]);
                    mat[row][col] = 1e9;
                }
                row--;
                col++;
            }
            if (ans.size() == n * n)
            {
                break;
            }
            row = max(0, row);
            col = min(n - 1, col);
            while (mat[row][col] == 1e9)
            {
                row++;
            }

            /*Going diagonally in downward direction*/
            while (col >= 0 && row < n)
            {
                if (row >= 0 && col < n && row < n && col >= 0)
                {
                    ans.push_back(mat[row][col]);
                    mat[row][col] = 1e9;
                }
                row++;
                col--;
            }
            if (ans.size() == n * n)
            {
                break;
            }
            row = min(n - 1, row);
            col = max(0, col);
            while (mat[row][col] == 1e9)
            {
                col++;
            }
        }
        return ans;
    }
};
