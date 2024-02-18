class Solution
{
public:
    void solve(Node *root, int &ans)
    {
        if (!root)
            return;
        if (root->left == NULL && root->right == NULL)
        {
            ans += root->data;
            return;
        }
        solve(root->left, ans);
        solve(root->right, ans);
    }
    int sumOfLeafNodes(Node *root)
    {
        int ans = 0;
        if (!root)
            return ans;
        if (root->left == NULL && root->right == NULL)
            return root->data;
        solve(root, ans);
        return ans;
    }
};