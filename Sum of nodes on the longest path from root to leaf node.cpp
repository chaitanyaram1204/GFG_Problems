struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
* /
    class Solution
{
public:
    pair<int, int> solve(Node *root)
    {
        if (!root)
        {
            return {0, 0};
        }
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);
        if (left.first > right.first)
        {
            return {left.first + 1, left.second + root->data};
        }
        else if (right.first > left.first)
        {
            return {right.first + 1, right.second + root->data};
        }
        return {left.first + 1, max(left.second, right.second) + root->data};
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        pair<int, int> ans = solve(root);
        return ans.second;
        // code here
    }
};