class Solution
{
public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    Node *insert(Node *root, int data)
    {
        if (root == NULL)
        {
            return new Node(data);
        }
        if (root->data >= data)
        {
            root->left = insert(root->left, data);
        }
        else if (root->data < data)
        {
            root->right = insert(root->right, data);
        }
        return root;
    }
    void insertTwo(Node *root1, Node *root2)
    {
        if (root2)
        {
            insert(root1, root2->data);
            insertTwo(root1, root2->left);
            insertTwo(root1, root2->right);
        }
    }
    void inorder(Node *root, vector<int> &arr)
    {
        if (root == NULL)
            return;
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }
    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int> arr;
        insertTwo(root1, root2);
        inorder(root1, arr);
        return arr;
    }
};