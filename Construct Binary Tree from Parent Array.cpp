class Solution
{
public:
    // Function to construct binary tree from parent array.
    Node *createTree(vector<int> parent)
    {
        unordered_map<int, vector<int>> children;
        int root;
        for (int i = 0; i < parent.size(); i++)
        {
            if (parent[i] == -1)
            {
                root = i;
                continue;
            }
            children[parent[i]].push_back(i);
        }

        Node *node = new Node(root);
        queue<Node *> q;
        q.push(node);
        Node *curr = node;
        while (!q.empty())
        {
            node = q.front();
            q.pop();
            int l = -1, r = -1;
            vector<int> child = children[node->data];

            if (child.size() == 2)
            {
                l = child[0];
                r = child[1];
            }
            else if (child.size() == 1)
            {
                l = child[0];
            }

            if (l != -1)
            {
                node->left = new Node(l);
                q.push(node->left);
            }

            if (r != -1)
            {
                node->right = new Node(r);
                q.push(node->right);
            }
        }
        return curr;
    }
};