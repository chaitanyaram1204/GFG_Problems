class Solution
{
public:
    bool valid(int i, int j, int n, int m)
    {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    vector<int> spirallyTraverse(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int cnt = 1;
        vector<int> ans;
        vector<vector<int>> visit(n, vector<int>(m, 0));
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int i = 0, j = 0;
        int k = 0, l = 0;
        ans.push_back(matrix[i][j]);
        visit[i][j] = 1;
        bool flag = false;
        while (cnt < n * m)
        {
            // cout << (i + dx[k]) << " ";
            // cout << (j + dy[k]) << endl;
            i = i + dx[k];
            j = j + dy[k];
            if (valid(i, j, n, m) && visit[i][j] == 0)
            {
                ans.push_back(matrix[i][j]);
                visit[i][j] = 1;
                cnt++;
                flag = false;
            }
            else
            {
                if (flag)
                    break;
                i = i - dx[k];
                j = j - dy[k];
                k = (k + 1) % 4;
                // cout << k << endl;

                flag = true;
            }
        }
        return ans;
    }
};