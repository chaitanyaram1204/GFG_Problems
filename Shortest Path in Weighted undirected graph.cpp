class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> adj[n + 1];
        for (auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<int> par(n + 1, -1);
        vector<int> dist(n + 1, INT_MAX);
        dist[1] = 0;
        pq.push({0, {1, -1}});
        while (!pq.empty())
        {
            int wt = pq.top().first;
            int node = pq.top().second.first;
            pq.pop();
            for (auto it : adj[node])
            {
                int adjnode = it.first;
                int edW = it.second;
                if (wt + edW < dist[adjnode])
                {
                    dist[adjnode] = wt + edW;
                    par[adjnode] = node;
                    pq.push({dist[adjnode], {adjnode, node}});
                }
            }
        }

        int cost = dist[n];
        if (cost == INT_MAX)
        {
            return {-1};
        }
        vector<int> ans;
        for (int v = n; v != -1; v = par[v])
        {
            ans.push_back(v);
        }
        ans.push_back(cost);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};