class Solution
{
public:
    // Function to find sum of all possible substrings of the given string.
    long long mod = 1e9 + 7;
    long long sumSubstrings(string s)
    {

        long long curr = 0;
        long long prev = s[0] - '0';
        // cout<<prev<<endl;
        long long ans = prev % mod;
        for (int i = 1; i < s.size(); i++)
        {
            curr = ((s[i] - '0') * (i + 1) + prev * 10) % mod;
            // cout<<curr<<endl;
            ans = (ans + curr) % mod;
            prev = curr;
        }
        return ans;
    }
};