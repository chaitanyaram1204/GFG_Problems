class Solution
{
public:
    // Function to return count of nodes at a given distance from leaf nodes.
    void solve(Node *root, int k, unordered_set<Node *> &ans, vector<Node *> &path)
    {
        if (!root)
            return;
        path.push_back(root);
        if (!root->left && !root->right)
        {
            int p = (int)path.size() - 1 - k;

            if (p > -1)
                ans.insert(path[p]);
        }
        solve(root->left, k, ans, path);
        solve(root->right, k, ans, path);
        path.pop_back();
    }
    int printKDistantfromLeaf(Node *root, int k)
    {
        unordered_set<Node *> se;
        vector<Node *> path;
        solve(root, k, se, path);
        return (int)se.size();
    }
};
