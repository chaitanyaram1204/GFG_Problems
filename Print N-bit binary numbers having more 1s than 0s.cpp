class Solution
{
public:
    void solve(int n, vector<string> &ans, string &str, int &oneCount, int &zeroCount)
    {
        if (n == 0 && zeroCount <= oneCount)
        {
            ans.push_back(str);
            return;
        }

        if (n < 0)
            return;

        if (zeroCount > oneCount)
            return;

        oneCount++;
        str += '1';
        solve(n - 1, ans, str, oneCount, zeroCount);
        oneCount--;
        zeroCount++;

        str = str.substr(0, str.size() - 1);
        str += '0';
        solve(n - 1, ans, str, oneCount, zeroCount);
        zeroCount--;
        str = str.substr(0, str.size() - 1);
    }
    vector<string> NBitBinary(int n)
    {
        vector<string> ans;
        int oneCount = 1;
        int zeroCount = 0;
        string str = "1";
        solve(n - 1, ans, str, oneCount, zeroCount);
        str = "0";
        oneCount = 0;
        zeroCount = 1;
        solve(n - 1, ans, str, oneCount, zeroCount);
        return ans;
    }
};