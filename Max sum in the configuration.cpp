class Solution
{
public:
    long long max_sum(int a[], int n)
    {
        long long sum = 0;
        long long prod = 0;

        for (int i = 0; i < n; i++)
        {
            sum += a[i];
            prod = (prod + i * 1LL * a[i]);
        }

        long long ans = prod;
        // cout<<sum<<" "<<prod<<endl;
        for (int i = 1; i < n; i++)
        {
            prod = prod - sum + (1LL * a[i - 1] * n);
            ans = max(ans, prod);
        }
        return ans;
    }
};
