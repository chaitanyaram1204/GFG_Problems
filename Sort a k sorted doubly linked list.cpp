class Solution
{
public:
    DLLNode *sortAKSortedDLL(DLLNode *head, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i <= k && head; i++)
        {
            pq.push(head->data);
            head = head->next;
        }

        DLLNode *h = NULL;
        DLLNode *t = NULL;

        while (!pq.empty())
        {
            DLLNode *n = new DLLNode(pq.top());
            pq.pop();

            if (h == NULL)
            {
                h = n;
                t = n;
            }
            else
            {
                DLLNode *temp = t;
                t->next = n;
                t = n;
                t->prev = temp;
            }
            if (head)
            {
                pq.push(head->data);
                head = head->next;
            }
        }
        return h;
    }
};