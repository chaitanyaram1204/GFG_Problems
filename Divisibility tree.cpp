class Solution
{
public:
    int count(int node, int par, vector<vector<int>> &adj, int &res)
    {
        int cnt = 0;
        for (auto child : adj[node])
        {
            if (child != par)
            {
                int temp = count(child, node, adj, res);
                cnt += temp;
                if (temp % 2 == 0)
                    res++;
            }
        }
        return cnt + 1;
    }
    int minimumEdgeRemove(int n, vector<vector<int>> edges)
    {
        int even = 0;
        vector<vector<int>> adj(n + 1);
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        count(1, -1, adj, even);
        return even;
    }
};