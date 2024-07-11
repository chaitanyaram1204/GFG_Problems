class Solution
{
public:
    vector<pair<int, int>> directions{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    bool valid(int ind, int i, int j, int n, vector<vector<int>> &grid)
    {
        return (i >= 0 && i < n && j >= 0 && j < n && grid[i][j] != 0 && grid[i][j] != ind);
    }
    int dfs(int ind, int i, int j, int n, vector<vector<int>> &grid)
    {
        grid[i][j] = ind;
        int ans = 1;
        for (dir : directions)
        {
            int x = i + dir.first;
            int y = j + dir.second;
            if (valid(ind, x, y, n, grid))
            {
                ans += dfs(ind, x, y, n, grid);
            }
        }
        return ans;
    }
    int MaxConnection(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int ind = 2, maxi = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    int ans = dfs(ind, i, j, n, grid);
                    mp[ind] = ans;
                    maxi = max(ans, maxi);
                    ind++;
                }
            }
        }
        // for(int i = 0; i<n; i++){
        //     for(int j = 0; j<n; j++){
        //         cout << grid[i][j] << " ";
        //     }
        //     cout<<endl;
        // }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int ans = 0;
                set<int> se;
                if (grid[i][j] == 0)
                {
                    if (i > 0)
                        se.insert(grid[i - 1][j]);
                    if (i < n - 1)
                        se.insert(grid[i + 1][j]);
                    if (j > 0)
                        se.insert(grid[i][j - 1]);
                    if (j < n - 1)
                        se.insert(grid[i][j + 1]);
                }
                for (auto it : se)
                {
                    // cout << " i " << i << " j " << j << " " << it << endl;
                    if (mp.find(it) != mp.end())
                    {
                        ans += mp[it];
                    }
                }
                ans++;
                maxi = max(maxi, ans);
            }
        }

        return maxi;
    }
};