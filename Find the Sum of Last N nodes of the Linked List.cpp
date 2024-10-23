class Solution
{
public:
    /*Structure of the node of the linled list is as

    struct Node {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }
    };
    */
    // your task is to complete this function
    // function should return sum of last n nodes
    int sumOfLastN_Nodes(struct Node *head, int n)
    {
        int count = 0;
        Node *temp = head;
        while (temp)
        {
            count++;
            temp = temp->next;
        }
        int totalsum = 0, i = 0;
        while (i < (count - n))
        {
            i++;
            head = head->next;
        }

        while (head)
        {
            totalsum += head->data;
            head = head->next;
        }
        return totalsum;
    }
};