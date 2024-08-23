
void leftValue(Node *root, vector<int> &ans, int level, int &maxLevel)
{
    if (root == NULL)
    {
        return;
    }

    // If this is the first node of its level
    if (maxLevel < level)
    {
        ans.push_back(root->data);
        maxLevel = level;
    }

    // Recur for left and right subtrees
    leftValue(root->left, ans, level + 1, maxLevel);
    leftValue(root->right, ans, level + 1, maxLevel);
}
vector<int> leftView(Node *root)
{
    vector<int> ans;
    int maxLevel = 0;
    leftValue(root, ans, 1, maxLevel);
    return ans;
}