/*
Structure of the node of the linked list is as
struct Node
{
    char data;
    struct Node *next;

    Node(char x){
        data = x;
        next = NULL;
    }

};
*/

class Solution
{
public:
    // task is to complete this function
    // function should return head to the list after making
    // necessary arrangements
    struct Node *arrangeCV(Node *head)
    {
        struct Node *dummy = new Node(-1);
        struct Node *dummy2 = new Node(-1);
        struct Node *ptr = dummy;
        struct Node *ptr2 = dummy2;

        while (head)
        {
            if (head->data == 'a' || head->data == 'e' || head->data == 'i' || head->data == 'o' || head->data == 'u')
            {
                struct Node *new_node = new Node(head->data);
                ptr->next = new_node;
                ptr = ptr->next;
            }
            else
            {
                struct Node *new_node = new Node(head->data);
                ptr2->next = new_node;
                ptr2 = ptr2->next;
            }

            head = head->next;
        }
        ptr->next = dummy2->next;
        return dummy->next;
    }
};