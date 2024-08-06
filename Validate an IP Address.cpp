class Solution
{
public:
    int isValid(string s)
    {
        string number = "";
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            if (ch == '.' && number.size() > 0 && number.size() <= 3)
            {
                int numbe = stoi(number);
                // cout << numbe << endl;
                if (numbe >= 0 && numbe <= 255)
                {
                    number = "";
                    count++;
                    continue;
                }
                else
                {
                    return 0;
                }
            }
            else if (ch >= 48 && ch <= 57)
            {
                if (ch == '0' && number.size() == 0 && i < s.size() - 1 && s[i + 1] != '.')
                    return 0;
                number += ch;
            }
            else
                return 0;
        }
        int numbe = stoi(number);
        // cout << numbe << endl;
        if (numbe >= 0 && numbe <= 255)
        {
            count++;
        }
        // cout << count << endl;
        return count == 4 ? 1 : 0;
    }
};