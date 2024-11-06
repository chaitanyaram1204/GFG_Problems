class Solution
{
public:
    int result = 0;
    void solve(Node *root, string curr)
    {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
        {
            curr += to_string(root->data);
            result += stoi(curr);
            return;
        }
        // cout << root->data << " " << curr << endl;
        solve(root->left, curr + to_string(root->data));
        solve(root->right, curr + to_string(root->data));
    }
    int treePathsSum(Node *root)
    {
        solve(root, "");
        return result;
    }
};