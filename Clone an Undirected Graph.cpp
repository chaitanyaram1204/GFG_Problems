class Solution
{
public:
    Node *dfs(Node *node, map<int, Node *> &mp)
    {
        mp[node->val] = new Node(node->val);
        for (auto it : node->neighbors)
        {
            if (mp.find(it->val) == mp.end())
            {
                mp[node->val]->neighbors.push_back(dfs(it, mp));
            }
            else
            {
                mp[node->val]->neighbors.push_back(mp[it->val]);
            }
        }
        return mp[node->val];
    }
    Node *cloneGraph(Node *node)
    {
        map<int, Node *> mp;
        return dfs(node, mp);
    }
};