struct Node
{
    int data;
    Node *left, *right;
};
* /

    class Solution
{
public:
    void solve(Node *root, vector<int> &ans, int level)
    {
        if (!root)
            return;
        if (level + 1 > ans.size())
        {
            ans.push_back(root->data);
        }
        else
        {
            ans[level] += root->data;
        }
        solve(root->left, ans, level + 1);
        solve(root->right, ans, level);
    }
    vector<int> diagonalSum(Node *root)
    {
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
};