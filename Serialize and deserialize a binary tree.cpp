class Solution
{
public:
    // Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root)
    {
        if (!root)
        {
            return {};
        }
        vector<int> v;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *node = q.front();
            q.pop();
            if (node == NULL)
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(node->data);
                q.push(node->left);
                q.push(node->right);
            }
        }
        return v;
    }

    // Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &A)
    {
        // Your code here
        if (A.size() == 0)
        {
            return NULL;
        }
        queue<Node *> q;
        Node *root = new Node(A[0]);
        q.push(root);
        int i = 1;
        while (!q.empty())
        {
            Node *node = q.front();
            q.pop();
            if (A[i] == -1)
            {
                node->left = NULL;
                i++;
            }
            else
            {
                Node *newNode = new Node(A[i]);
                node->left = newNode;
                q.push(newNode);
                i++;
            }
            if (A[i] == -1)
            {
                node->right = NULL;
                i++;
            }
            else
            {
                Node *newNode = new Node(A[i]);
                node->right = newNode;
                q.push(newNode);
                i++;
            }
        }
        return root;
    }
};