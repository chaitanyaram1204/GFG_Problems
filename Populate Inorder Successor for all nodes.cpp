class Solution
{
public:
    stack<Node *> st;
    void populateNext(Node *root)
    {
        if (root == NULL)
            return;
        populateNext(root->right);
        if (!st.empty())
            root->next = st.top();
        st.push(root);
        populateNext(root->left);
    }
};