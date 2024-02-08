class Solution
{
public:
    bool isSame(Node *root, int &d, int depth = 0)
    {
        if (!root)
            return true;
        if (!isSame(root->left, d, depth + 1))
            return false;
        if (!isSame(root->right, d, depth + 1))
            return false;
        if (root->right == NULL && root->left == NULL)
        {
            if (d == -1)
                d = depth;
            else if (d != depth)
                return false;
        }
        return true;
    }
    bool check(Node *root)
    {
        int d = -1;
        return isSame(root, d);
    }
};
