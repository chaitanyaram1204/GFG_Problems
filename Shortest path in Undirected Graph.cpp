class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {
        vector<int> adj[N];

        for (auto edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> dist(N, 1e8);
        vector<int> vis(N, 0);

        vis[src] = 1;
        queue<int> q;
        q.push(src);
        dist[src] = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto it : adj[node])
            {
                if (!vis[it] && dist[node] + 1 < dist[it])
                {
                    vis[it] = 1;
                    dist[it] = 1 + dist[node];
                    q.push(it);
                }
            }
        }

        for (auto &it : dist)
        {
            if (it == 1e8)
            {
                it = -1;
            }
        }

        return dist;
    }
};