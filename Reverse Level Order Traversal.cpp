

/*
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
vector<int> reverseLevelOrder(Node *root)
{
    vector<int> ans;
    stack<Node *> st;
    queue<Node *> q;
    if (!root)
        return ans;
    q.push(root);
    while (!q.empty())
    {
        root = q.front();
        q.pop();
        st.push(root);

        if (root->right)
            q.push(root->right);
        if (root->left)
            q.push(root->left);
    }

    while (!st.empty())
    {
        ans.push_back(st.top()->data);
        st.pop();
    }
    return ans;
}