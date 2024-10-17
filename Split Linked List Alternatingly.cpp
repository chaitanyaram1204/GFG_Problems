class Solution
{
public:
    // Function to split a linked list into two lists alternately
    vector<Node *> alternatingSplitList(struct Node *head)
    {
        Node *curr1 = new Node(-1);
        Node *curr2 = new Node(-1);
        Node *root1 = curr1;
        Node *root2 = curr2;
        int i = 0;
        while (head)
        {
            if (i % 2)
            {
                root2->next = new Node(head->data);
                root2 = root2->next;
            }
            else
            {
                root1->next = new Node(head->data);
                root1 = root1->next;
            }
            head = head->next;
            i++;
        }
        return {curr1->next, curr2->next};
    }
};