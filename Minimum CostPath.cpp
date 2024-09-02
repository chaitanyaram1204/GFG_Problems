class Solution
{
public:
    // Function to return the minimum cost to react at bottom
    // right cell from top left cell.
    int minimumCostPath(vector<vector<int>> &grid)
    {
        vector<pair<int, int>> directions{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1e9));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({grid[n - 1][m - 1], {n - 1, m - 1}});
        dp[n - 1][m - 1] = grid[n - 1][m - 1];

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int dist = it.first;
            int i = it.second.first;
            int j = it.second.second;
            if (i == 0 && j == 0)
            {
                continue;
            }
            for (auto dire : directions)
            {
                int u = i + dire.first;
                int v = j + dire.second;
                if (u >= 0 && u < n && v >= 0 && v < m && dp[u][v] > dist + grid[u][v])
                {
                    dp[u][v] = dist + grid[u][v];
                    pq.push({dp[u][v], {u, v}});
                }
            }
        }

        return dp[0][0];
    }
};