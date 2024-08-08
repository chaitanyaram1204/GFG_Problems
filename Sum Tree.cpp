class Solution
{
public:
    int util(Node *root, bool &ans)
    {
        if (!root)
            return 0;

        int l = util(root->left, ans);
        int r = util(root->right, ans);

        if (!root->left && !root->right)
            return root->data;

        if (l + r != root->data)
            ans = false;
        return 2 * root->data;
    }
    bool isSumTree(Node *root)
    {
        // Your code here
        bool ans = true;
        util(root, ans);
        return ans;
    }
};