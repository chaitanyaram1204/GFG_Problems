class Solution
{
public:
    vector<int> bracketNumbers(string str)
    {
        int t = 1;
        int n = str.length();
        vector<int> ans;
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (str[i] == '(')
            {
                st.push(t);
                ans.push_back(t);
                t++;
            }
            else if (str[i] == ')')
            {
                ans.push_back(st.top());
                st.pop();
            }
        }
        return ans;
    }
};