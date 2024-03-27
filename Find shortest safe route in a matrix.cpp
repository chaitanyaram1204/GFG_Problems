class Solution
{
public:
    int findShortestPath(vector<vector<int>> &mat)
    {
        int r = mat.size();
        int c = mat[0].size();

        vector<vector<int>> a(r, vector<int>(c, 1));
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (mat[i][j] == 0)
                {
                    a[i][j] = 0;

                    for (int k = 0; k < 4; k++)
                    {
                        int nrow = delrow[k] + i;
                        int ncol = delcol[k] + j;

                        if (nrow >= 0 && ncol >= 0 && nrow < r && ncol < c)
                        {
                            a[nrow][ncol] = 0;
                        }
                    }
                }
            }
        }

        vector<vector<int>> vis(r, vector<int>(c, 0));
        queue<pair<int, pair<int, int>>> q;

        for (int i = 0; i < r; i++)
        {
            if (a[i][0] == 1)
            {
                q.push({1, {i, 0}});
            }
        }

        while (!q.empty())
        {
            auto temp = q.front();
            q.pop();
            int dist = temp.first;
            int row = temp.second.first;
            int col = temp.second.second;

            if (col == c - 1)
                return dist;
            vis[row][col] = 1;

            for (int k = 0; k < 4; k++)
            {
                int nrow = delrow[k] + row;
                int ncol = delcol[k] + col;

                if (nrow >= 0 && ncol >= 0 && nrow < r & ncol < c && a[nrow][ncol] == 1 && vis[nrow][ncol] == 0)
                {
                    q.push({dist + 1, {nrow, ncol}});
                }
            }
        }

        return -1;
    }
};