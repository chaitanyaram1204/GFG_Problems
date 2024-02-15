class Solution
{
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &in, vector<int> &vis,
             int &cc, int &odd)
    {
        vis[node] = 1;
        odd = odd or (in[node] & 1);
        cc++;
        for (auto it : adj[node])
        {
            if (!vis[it])
                dfs(it, adj, in, vis, cc, odd);
        }
    }
    int isPossible(vector<vector<int>> paths)
    {
        int n = paths.size();
        vector<vector<int>> adj(n);
        vector<int> in(n, 0), vis(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (paths[i][j])
                {
                    adj[i].push_back(j);
                    in[j]++;
                }
            }
        }
        int odd = 0;
        int cc = 0;
        dfs(0, adj, in, vis, cc, odd);

        return cc == n and !odd;
    }
};