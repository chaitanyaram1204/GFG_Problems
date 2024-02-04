class Solution
{
public:
    int length(Node *head1)
    {
        int len = 0;
        while (head1)
        {
            len++;
            head1 = head1->next;
        }
        return len;
    }
    Node *reverse(Node *head)
    {
        Node *prev = NULL, *curr = head, *next;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    Node *subLinkedList(Node *head1, Node *head2)
    {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        while (head1 and head1->data == 0)
            head1 = head1->next;
        while (head2 and head2->data == 0)
            head2 = head2->next;
        int n1 = length(head1);
        int n2 = length(head2);
        if (n2 > n1)
            swap(head1, head2);
        if (n1 == n2)
        {
            Node *temp1 = head1, *temp2 = head2;
            if (!temp1 and !temp2)
                return new Node(0);
            while (temp1->data == temp2->data)
            {
                temp1 = temp1->next;
                temp2 = temp2->next;
                if (!temp1 or !temp2)
                    return new Node(0);
            }
            if (temp2->data > temp1->data)
                swap(head1, head2);
        }
        head1 = reverse(head1);
        head2 = reverse(head2);
        Node *ans = NULL;
        Node *temp1 = head1, *temp2 = head2;
        while (temp1)
        {
            int data = 0;
            if (temp2)
                data = temp2->data;
            if (data > temp1->data)
            {
                temp1->data += 10;
                temp1->next->data -= 1;
            }
            Node *res = new Node(temp1->data - data);
            res->next = ans;
            ans = res;
            temp1 = temp1->next;
            if (temp2)
                temp2 = temp2->next;
        }
        while (ans->next and ans->data == 0)
            ans = ans->next;
        return ans;
    }
};