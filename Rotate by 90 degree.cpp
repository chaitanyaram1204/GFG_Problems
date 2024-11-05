void rotate(vector<vector<int>> &mat)
{
    // Your code goes here
    int n = mat.size();
    int m = mat[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            // cout << mat[i][j] << " " << mat[j][i] << endl;
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
            // cout << mat[i][j] << " " << mat[j][i] << endl;
        }
    }

    for (int i = 0; i < n; i++)
    {
        reverse(mat[i].begin(), mat[i].end());
    }
}