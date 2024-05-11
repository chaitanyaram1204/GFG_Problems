class Solution
{
public:
    vector<long long> jugglerSequence(long long n)
    {
        vector<long long> ans;
        ans.push_back(n);
        while (n != 1)
        {
            if (n % 2 == 1)
            {
                n = pow(n, 1.5);
            }
            else
            {
                n = pow(n, 0.5);
            }
            ans.push_back(n);
        }
        return ans;
    }
};