class Solution
{

public:
    int findSwapValues(int a[], int n, int b[], int m)
    {
        int sum1 = 0;
        sum1 = accumulate(a, a + n, sum1);
        int sum2 = 0;
        sum2 = accumulate(b, b + m, sum2);
        //  cout<<sum1<<" "<<sum2<<endl;
        sort(a, a + n);
        sort(b, b + m);

        int diff = abs(sum1 - sum2);

        if (diff % 2 == 1)
            return -1;
        // cout<<"hello"<<endl;
        int target = diff / 2;

        int i = 0, j = 0;
        while (i < n && j < m)
        {
            int d = abs(a[i] - b[j]);

            if (d == target)
            {
                return 1;
            }

            if (d > target)
            {
                if (a[i] > b[j])
                {
                    j++;
                }
                else
                {
                    i++;
                }
            }
            else
            {
                if (a[i] > b[j])
                {
                    i++;
                }
                else
                {
                    j++;
                }
            }
        }
        return -1;
    }
};