class Solution
{
public:
    void getParents(Node *root, unordered_map<Node *, Node *> &parent)
    {
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            root = q.front();
            q.pop();
            if (root->left)
            {
                parent[root->left] = root;
                q.push(root->left);
            }
            if (root->right)
            {
                parent[root->right] = root;
                q.push(root->right);
            }
        }
    }

    Node *getNode(Node *root, int target)
    {
        if (root == NULL || root->data == target)
            return root;
        Node *left = getNode(root->left, target);
        Node *right = getNode(root->right, target);
        if (left)
            return left;
        return right;
    }

    int minTime(Node *root, int target)
    {
        Node *node = getNode(root, target);
        if (node == NULL)
            return 0;

        unordered_map<Node *, Node *> parent;
        getParents(root, parent);

        unordered_set<Node *> se;
        int count = 0;

        queue<Node *> q;
        q.push(node);

        while (!q.empty())
        {

            int size = q.size();
            bool flag = false;

            for (int i = 0; i < size; i++)
            {
                node = q.front();
                q.pop();
                se.insert(node);

                if (node->left && se.find(node->left) == se.end())
                {
                    flag = true;
                    q.push(node->left);
                }

                if (node->right && se.find(node->right) == se.end())
                {
                    flag = true;
                    q.push(node->right);
                }

                if (parent.count(node) && se.find(parent[node]) == se.end())
                {
                    flag = true;
                    q.push(parent[node]);
                }
            }
            if (flag)
                count++;
        }

        return count;
    }
};