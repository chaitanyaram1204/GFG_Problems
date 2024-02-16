class Solution
{
public:
    void inorder(Node *root, vector<int> &ans)
    {
        if (root)
        {
            inorder(root->left, ans);
            ans.push_back(root->data);
            inorder(root->right, ans);
        }
    }
    Node *flattenBST(Node *root)
    {
        if (!root)
            return NULL;
        vector<int> ans;
        inorder(root, ans);
        root->left = NULL;
        root->right = NULL;
        root->data = ans[0];
        Node *FinalAns = root;
        for (int i = 1; i < ans.size(); i++)
        {
            Node *temp = new Node(ans[i]);
            root->right = temp;
            root = temp;
        }
        return FinalAns;
    }
};