class Solution
{
public:
    // Should return decimal equivalent modulo 1000000007 of binary linked list
    long long unsigned int decimalValue(Node *head)
    {
        long long int ans = 0;
        while (head)
        {
            ans = (ans << 1 | head->data) % 1000000007;
            head = head->next;
        }
        return ans;
    }
};
