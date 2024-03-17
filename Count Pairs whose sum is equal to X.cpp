class Solution
{
public:
    // your task is to complete this function
    int countPairs(struct Node *head1, struct Node *head2, int x)
    {
        int count = 0;
        unordered_set<int> seen;

        Node *temp2 = head2;
        while (temp2 != nullptr)
        {
            seen.insert(temp2->data);
            temp2 = temp2->next;
        }

        Node *temp1 = head1;
        while (temp1 != nullptr)
        {
            int complement = x - temp1->data;
            if (seen.find(complement) != seen.end())
            {
                count++;
            }
            temp1 = temp1->next;
        }

        return count;
    }
};