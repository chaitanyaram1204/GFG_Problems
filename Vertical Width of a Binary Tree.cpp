class Solution
{
public:
    // Function to find the vertical width of a Binary Tree.
    int verticalWidth(Node *root)
    {
        if (root == NULL)
            return 0;

        int mini = INT_MAX, maxi = INT_MIN;
        queue<pair<int, Node *>> q;

        q.push({0, root});

        while (!q.empty())
        {

            pair<int, Node *> temp = q.front();
            q.pop();

            mini = min(mini, temp.first);
            maxi = max(maxi, temp.first);
            if (temp.second->left)
                q.push({temp.first - 1, temp.second->left});
            if (temp.second->right)
                q.push({temp.first + 1, temp.second->right});
        }
        return maxi - mini + 1;
    }
};