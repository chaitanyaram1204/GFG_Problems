class Solution
{
public:
    // Function should return all the ancestor of the target node
    bool solve(struct Node *root, int target, vector<int> &ans)
    {
        if (root == NULL)
            return false;
        if (root->data == target)
            return true;
        if (solve(root->left, target, ans) || solve(root->right, target, ans))
        {
            ans.push_back(root->data);
            return true;
        }
        return false;
    }
    vector<int> Ancestors(struct Node *root, int target)
    {
        vector<int> ans;
        solve(root, target, ans);
        return ans;
    }
};
