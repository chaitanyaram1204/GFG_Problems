class Solution
{
public:
    bool hasPathSum(Node *root, int target)
    {
        if (root == NULL)
        {
            return false;
        }
        target -= root->data;
        if (!root->left && !root->right && 0 == target)
        {
            return true;
        }
        bool left = hasPathSum(root->left, target);
        bool right = hasPathSum(root->right, target);
        return left | right;
    }
};
s