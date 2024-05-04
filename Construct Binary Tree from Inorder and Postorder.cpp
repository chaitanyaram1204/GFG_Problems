/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
public:
    Node *solve(int &postIndx, int start, int end, int in[], int post[])
    {
        if (postIndx < 0)
            return NULL;

        if (start > end)
            return NULL;

        int ind = start;
        for (; ind <= end; ind++)
        {
            if (post[postIndx] == in[ind])
                break;
        }

        Node *root = new Node(post[postIndx--]);
        // cout<<post[1+postIndx]<<endl;

        root->right = solve(postIndx, ind + 1, end, in, post);
        root->left = solve(postIndx, start, ind - 1, in, post);

        return root;
    }

    // Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int in[], int post[], int n)
    {
        int postIndx = n - 1;
        return solve(postIndx, 0, n - 1, in, post);
    }
};