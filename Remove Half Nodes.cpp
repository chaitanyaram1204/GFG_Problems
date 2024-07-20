class Solution
{
public:
    Node *solve(Node *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        root->left = solve(root->left);
        root->right = solve(root->right);
        Node *temp = root;
        if (root->left && root->right == NULL)
        {
            temp = root->left;
            root = NULL;
        }
        else if (root->left == NULL && root->right)
        {
            temp = root->right;
            root = NULL;
        }
        return temp;
    }
    Node *RemoveHalfNodes(Node *root)
    {
        return solve(root);
        return root;
    }
};