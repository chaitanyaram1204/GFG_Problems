class Solution
{
public:
    // Function to add two numbers represented by linked list.
    Node *Reverse(struct Node *list)
    {
        struct Node *prev = NULL;
        while (list != NULL)
        {
            struct Node *next = list->next;
            list->next = prev;
            prev = list;
            list = next;
        }
        return prev;
    }

    Node *trim(struct Node *list)
    {
        if (list->data == 0)
        {
            while (list->data == 0)
            {
                list = list->next;
                if (list == NULL)
                    return new Node(0);
            }
        }
        return list;
    }

    struct Node *addTwoLists(struct Node *num1, struct Node *num2)
    {
        struct Node *dummy = new Node(-1);
        num1 = Reverse(num1);
        num2 = Reverse(num2);

        int carry = 0;
        int sum = 0;
        Node *temp = dummy;
        while (num1 != NULL || num2 != NULL || carry)
        {
            sum = 0;
            if (num1)
            {
                sum += num1->data;
                num1 = num1->next;
            }
            if (num2)
            {
                sum += num2->data;
                num2 = num2->next;
            }

            sum += carry;

            temp->next = new Node(sum % 10);
            temp = temp->next;
            carry = sum / 10;
        }
        dummy->next = Reverse(dummy->next);
        dummy->next = trim(dummy->next);
        return dummy->next;
    }
};