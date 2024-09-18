class Solution
{
public:
    // Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> st;
        for (auto &e : x)
        {
            if (e == '(' || e == '[' || e == '{')
            {
                st.push(e);
            }
            else
            {
                if (st.empty())
                {
                    return false;
                }
                else
                {
                    auto curr = st.top();
                    if (e == ')' && curr != '(')
                    {
                        return false;
                    }
                    else if (e == '}' && curr != '{')
                    {
                        return false;
                    }
                    else if (e == ']' && curr != '[')
                    {
                        return false;
                    }
                    else
                    {
                        st.pop();
                    }
                }
            }
        }
        if (st.empty())
        {
            return true;
        }
        return false;
    }
};