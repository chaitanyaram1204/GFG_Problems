class Solution
{
public:
    // your task is to complete this function
    void sort(Node **head)
    {
        Node *Ahead = new Node(0);
        Node *Dhead = new Node(0);

        Node *ascn = Ahead;
        Node *dscn = Dhead;
        Node *head1 = *head;
        while (head1)
        {
            ascn->next = head1;
            ascn = ascn->next;
            head1 = head1->next;
            if (head1)
            {
                dscn->next = head1;
                dscn = dscn->next;
                head1 = head1->next;
            }
        }

        ascn->next = NULL;
        dscn->next = NULL;

        Ahead = (Ahead)->next;
        Dhead = (Dhead)->next;

        // Reverse Descending to ascending
        Node *prev = NULL;
        Node *curr = Dhead;
        Node *next;

        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        Dhead = prev;

        // Merge two;

        Node *temp = Ahead;
        while (temp->next)
        {
            temp = temp->next;
        }

        temp->next = Dhead;
    }
};