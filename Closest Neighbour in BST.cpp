class Solution
{
public:
    void inordertraversal(Node *root, vector<int> &res)
    {
        if (root == NULL)
        {
            return;
        }
        inordertraversal(root->left, res);
        res.push_back(root->key);
        inordertraversal(root->right, res);
    }
    int findMaxForN(Node *root, int n)
    {
        vector<int> res;
        inordertraversal(root, res);
        sort(res.begin(), res.end());

        int ans = -1;

        for (int i = res.size() - 1; i >= 0; i--)
        {
            if (res[i] <= n)
            {
                ans = res[i];
                break;
            }
        }

        return ans;
    }
};