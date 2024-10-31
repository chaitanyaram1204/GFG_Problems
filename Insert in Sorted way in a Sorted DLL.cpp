class Solution
{
public:
    Node *sortedInsert(Node *head, int x)
    {
        Node *curr = head;
        // Node* nxt=curr->next;
        Node *New = new Node();
        New->data = x;
        if (head->data > x)
        {
            New->next = head;
            head->prev = New;
            New->prev = NULL;
            return New;
        }
        while (curr->next != NULL && x > curr->next->data)
        {
            curr = curr->next;
        }
        Node *nxt = curr->next;
        curr->next = New;
        curr->next->prev = curr;
        curr->next->next = nxt;
        return head;
    }
};