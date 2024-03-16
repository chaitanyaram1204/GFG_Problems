class Solution
{
public:
    // Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del_node)
    {
        int val = del_node->next->data;
        Node *temp = del_node->next->next;
        del_node->data = val;
        del_node->next = temp;
    }
};