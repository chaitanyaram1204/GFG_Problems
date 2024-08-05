class Solution
{
public:
    vector<int> bottomView(Node *root)
    {
        if (root == NULL)
            return {};
        map<int, int> mp;
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            root = q.front().first;
            int level = q.front().second;
            q.pop();
            mp[level] = root->data;
            if (root->left)
                q.push({root->left, level - 1});
            if (root->right)
                q.push({root->right, level + 1});
        }
        vector<int> bottomview;
        for (auto it : mp)
        {
            bottomview.push_back(it.second);
        }
        return bottomview;
    }
};