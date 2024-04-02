/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

};
*/

class Solution
{
public:
    int ans = INT_MAX;
    int prev = -1;
    void solve(Node *root)
    {
        if (root)
        {
            solve(root->left);
            if (prev != -1)
            {
                ans = min(ans, abs(prev - root->data));
            }
            prev = root->data;
            solve(root->right);
        }
    }
    int absolute_diff(Node *root)
    {
        solve(root);
        return ans;
    }
};