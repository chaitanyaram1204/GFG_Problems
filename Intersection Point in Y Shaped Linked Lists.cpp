class Solution
{
public:
    // Function to find intersection point in Y shaped Linked Lists.
    int intersectPoint(Node *head1, Node *head2)
    {
        if (head1 == NULL || head2 == NULL)
            return -1;
        if (head1 == head2)
            return head1->data;
        Node *dup1 = head1;
        Node *dup2 = head2;
        while (dup1 != dup2)
        {
            dup1 = dup1->next == NULL ? head2 : dup1->next;
            dup2 = dup2->next == NULL ? head1 : dup2->next;
            if (dup1 == dup2)
                return dup1->data;
        }
        return -1;
    }
};