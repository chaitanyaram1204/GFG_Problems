class Solution
{
public:
    Node *deleteMid(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return NULL;
        Node *prev = NULL;
        Node *slow = head;
        Node *fast = head;

        while (fast->next && fast->next->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast->next)
        {
            prev = slow;
            slow = slow->next;
        }
        prev->next = slow->next;
        slow->next = NULL;
        return head;
    }
};