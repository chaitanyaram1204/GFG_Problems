class Solution
{
public:
    // Function to rotate a linked list.
    Node *rotate(Node *head, int k)
    {
        Node *tail = head;
        Node *next = head->next;
        Node *required = head;
        k--;
        while (tail->next != NULL)
        {
            if (k > 0)
            {
                k--;
                required = required->next;
                if (required->next)
                    next = required->next;
                else
                    return head;
            }
            tail = tail->next;
        }
        tail->next = head;
        required->next = NULL;
        return next;
    }
};