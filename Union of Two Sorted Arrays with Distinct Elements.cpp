class Solution
{
public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b)
    {
        set<int> ans;
        for (int i = 0; i < a.size(); i++)
            ans.insert(a[i]);
        for (int i = 0; i < b.size(); i++)
            ans.insert(b[i]);
        vector<int> res;
        for (auto k : ans)
        {
            res.push_back(k);
        }
        return res;
    }
};