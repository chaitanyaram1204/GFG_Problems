class Solution
{
public:
    /* Should return data of middle node. If linked list is empty, then -1 */
    int getMiddle(Node *head)
    {
        int count = 0;
        Node *temp = head;
        while (temp)
        {
            count++;
            temp = temp->next;
        }

        count /= 2;
        while (count--)
        {
            head = head->next;
        }
        return head->data;
    }
};