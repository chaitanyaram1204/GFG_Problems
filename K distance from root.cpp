/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution
{
public:
    void solve(Node *root, int k, int count, vector<int> &ans)
    {
        if (!root)
            return;

        if (count == k)
        {
            ans.push_back(root->data);
            return;
        }

        solve(root->left, k, count + 1, ans);
        solve(root->right, k, count + 1, ans);
    }
    // function should print the nodes at k distance from root
    vector<int> Kdistance(struct Node *root, int k)
    {
        vector<int> ans;

        solve(root, k, 0, ans);

        return ans;
    }
};