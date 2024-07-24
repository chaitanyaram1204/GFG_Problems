class Solution
{
public:
    // Function to check whether a Binary Tree is BST or not.
    bool solve(Node *root, int mini = INT_MIN, int maxi = INT_MAX)
    {
        if (root == NULL)
        {
            return true;
        }
        if (root->data < mini || maxi < root->data)
            return false;
        bool left = solve(root->left, mini, root->data - 1);
        bool right = solve(root->right, root->data + 1, maxi);

        return left && right;
    }

    bool isBST(Node *root)
    {
        return solve(root);
    }
};