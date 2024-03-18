struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
* /

    class Solution
{
public:
    // Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                root = q.front();
                q.pop();
                ans.push_back(root->data);
                if (root->left)
                    q.push(root->left);
                if (root->right)
                    q.push(root->right);
            }
        }
        return ans;
    }
};