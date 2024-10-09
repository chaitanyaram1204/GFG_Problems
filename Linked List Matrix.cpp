class Solution
{
public:
    Node *constructLinkedMatrix(vector<vector<int>> &mat)
    {
        Node *dummy = new Node(0);
        Node *temp = dummy;
        int n = mat.size();

        for (int i = 0; i < n; i++) // Initialising only first row.
        {
            temp->right = new Node(mat[0][i]);
            temp = temp->right;
        }

        Node *prev = dummy->right;  // Point to previous row
        for (int i = 1; i < n; i++) // For rest of the rows
        {
            Node *dummy1 = new Node(0);
            Node *orgD1 = dummy1;
            for (int j = 0; j < n; j++)
            {
                dummy1->right = new Node(mat[i][j]);
                dummy1 = dummy1->right;
                prev->down = dummy1;
                prev = prev->right;
            }

            prev = orgD1->right;
            delete orgD1;
        }
        Node *head = dummy->right;
        delete dummy;
        return head;
    }
};