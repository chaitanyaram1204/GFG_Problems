class Solution
{
public:
    int findMaxDiff(vector<int> &arr)
    {
        stack<int> st;
        int n = arr.size();
        vector<int> ls(n, 0);
        vector<int> rs(n, 0);
        st.push(arr[0]);
        for (int i = 1; i < n; i++)
        {
            while (!st.empty() && st.top() >= arr[i])
                st.pop();
            if (!st.empty())
            {
                ls[i] = st.top();
                st.push(arr[i]);
            }
            else
            {
                st.push(arr[i]);
                ls[i] = 0;
            }
        }
        while (!st.empty())
            st.pop();
        st.push(arr[n - 1]);
        for (int i = n - 2; i >= 0; i--)
        {
            while (!st.empty() && st.top() >= arr[i])
                st.pop();
            if (!st.empty())
            {
                rs[i] = st.top();
                st.push(arr[i]);
            }
            else
            {
                st.push(arr[i]);
                rs[i] = 0;
            }
        }
        int maxDiff = 0;
        for (int i = 0; i < n; i++)
        {
            maxDiff = max(maxDiff, abs(ls[i] - rs[i]));
        }
        return maxDiff;
    }
};