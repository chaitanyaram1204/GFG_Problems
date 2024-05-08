class Solution
{
public:
    vector<vector<int>> ans;

    void help(Node *root, vector<int> temp)
    {

        temp.push_back(root->data);
        if (!root->left && !root->right)
        {
            ans.push_back(temp);
            return;
        }
        if (root->left)
            help(root->left, temp);
        if (root->right)
            help(root->right, temp);
        temp.pop_back();
    }

    vector<vector<int>> Paths(Node *root)
    {
        help(root, {});
        return ans;
    }
};