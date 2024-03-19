class Solution
{
public:
    int ans;
    int root(int i, vector<int> &parent)
    {
        while (parent[i] != i)
        {
            parent[i] = parent[parent[i]];
            i = parent[i];
        }
        return i;
    }
    int Union(int a, int b, vector<int> &p, vector<int> &sz)
    {
        int ra = root(a, p);
        int rb = root(b, p);
        if (ra == rb)
            return sz[ra] * sz[ra];
        if (sz[ra] < sz[rb])
        {
            swap(ra, rb);
            swap(a, b);
        }
        ans += sz[ra] * sz[rb];
        p[rb] = ra;
        sz[ra] += sz[rb];
        return ans;
    }
    vector<int> maximumWeight(int n, vector<vector<int>> edges, int q, vector<int> &queries)
    {
        ans = 0;
        vector<int> parent(n + 1, 0), sz(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            sz[i] = 1;
        }
        vector<pair<int, pair<int, int>>> wt;
        for (int i = 0; i < edges.size(); i++)
            wt.push_back({edges[i][2], {edges[i][0], edges[i][1]}});
        sort(wt.begin(), wt.end());
        map<int, int> mp;
        for (int i = 0; i < n - 1; i++)
        {
            int val = wt[i].first;
            int firstnode = wt[i].second.first;
            int secondnode = wt[i].second.second;
            mp[val] = Union(firstnode, secondnode, parent, sz);
        }
        vector<int> res;
        for (int i = 0; i < q; i++)
        {
            auto val = mp.upper_bound(queries[i]);
            if (val == mp.begin())
                res.push_back(0);
            else
            {
                val--;
                res.push_back(val->second);
            }
        }
        return res;
    }
};