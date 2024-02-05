class Solution
{
public:
    Node sortedInsert(Node head, int data)
    {
        if (head == NULL)
        {
            Node *new_node = new Node(data);
            new_node->next = new_node;
            return new_node;
        }
        Node *temp1 = head;
        while (true)
        {
            if (data <= head->next->data && data >= head->data)
            {
                Node *new_node = new Node(data);
                // Node* temp = head->next;
                new_node->next = head->next;
                head->next = new_node;
                break;
            }
            else if (head->next != temp1)
                head = head->next;
            else
            {
                Node *new_node = new Node(data);
                head->next = new_node;
                new_node->next = temp1;
                if (data <= temp1->data)
                    temp1 = new_node;
                break;
            }
        }
        return temp1;
    }
};