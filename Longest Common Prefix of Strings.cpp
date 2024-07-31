class Solution
{
public:
    string longestCommonPrefix(vector<string> arr)
    {
        string smallest;
        int mini = INT_MAX;
        for (auto curr : arr)
        {
            if (curr.size() < mini)
            {
                mini = curr.size();
                smallest = curr;
            }
        }

        for (auto it : arr)
        {
            string curr = it.substr(0, mini);
            if (smallest.size() == 0)
                return "-1";
            if (curr == smallest)
            {
                continue;
            }
            string temp = "";
            for (int i = 0; i < curr.size(); i++)
            {
                if (curr[i] == smallest[i])
                {
                    temp += curr[i];
                }
                else
                {
                    smallest = temp;
                    break;
                }
            }
        }
        if (smallest.size() == 0)
            return "-1";

        return smallest;
    }
};