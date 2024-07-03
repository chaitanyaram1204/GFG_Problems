class Solution
{
public:
    Node *removeAllDuplicates(struct Node *head)
    {
        if (!head)
            return NULL;

        unordered_map<int, int> mp;
        Node *temp = head;

        while (temp)
        {
            mp[temp->data]++;
            temp = temp->next;
        }

        Node *dummy = new Node(-1);
        Node *newList = dummy;

        temp = head;
        while (temp)
        {
            if (mp[temp->data] == 1)
            {
                newList->next = new Node(temp->data);
                newList = newList->next;
            }
            temp = temp->next;
        }

        Node *newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};