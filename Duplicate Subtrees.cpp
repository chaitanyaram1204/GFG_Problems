class Solution
{
public:
    string solve(Node *root, unordered_map<string, int> &mp, vector<Node *> &ans)
    {
        if (!root)
            return "@";
        string curr = solve(root->left, mp, ans) + to_string(root->data) + solve(root->right, mp, ans);

        mp[curr]++;

        if (mp[curr] == 2)
            ans.push_back(root);

        return curr;
    }
    vector<Node *> printAllDups(Node *root)
    {
        unordered_map<string, int> mp;
        vector<Node *> ans;

        solve(root, mp, ans);
        return ans;
    }
};