class Solution
{
private:
    bool check(string front)
    {
        int st = 0, end = front.size() - 1;
        while (st < end)
        {
            if (front[st++] != front[end--])
                return false;
        }
        return true;
    }

public:
    bool compute(Node *head)
    {
        string front = "";
        while (head)
        {
            string c = head->data;
            front += c;
            head = head->next;
        }

        return check(front);
    }
};