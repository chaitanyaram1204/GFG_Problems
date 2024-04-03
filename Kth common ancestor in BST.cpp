class Solution
{
public:
    void solve(Node *root, int x, int y, vector<int> &anc)
    {
        if (root == NULL)
        {
            return;
        }
        anc.push_back(root->data); // storing the path.
        if (root->data < x && root->data < y)
        {
            solve(root->right, x, y, anc);
        }
        else if (root->data > x && root->data > y)
        {
            solve(root->left, x, y, anc);
        }

        return;
    }

    int kthCommonAncestor(Node *root, int k, int x, int y)
    {
        vector<int> anc;
        solve(root, x, y, anc);
        /*  for(auto x : anc) {
              cout << x << " ";
          }
          cout << endl;*/
        int n = anc.size();
        if (n < k)
        {
            return -1;
        }
        return anc[n - k];
    }
};