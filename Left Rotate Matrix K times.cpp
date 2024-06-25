class Solution
{
public:
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat)
    {
        int m = mat.size();

        for (int i = 0; i < m; i++)
        {

            int n = mat[0].size();

            k = k % n;

            reverse(mat[i].begin(), mat[i].begin() + k);

            reverse(mat[i].begin() + k, mat[i].end());

            reverse(mat[i].begin(), mat[i].end());
        }

        return mat;
    }
};