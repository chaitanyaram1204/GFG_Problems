class Solution
{
public:
    int maxLength(string &stri)
    {
        // code here
        int acount = 0;
        int bcount = 0;
        int frontCount = 0;
        int backCount = 0;

        for (auto ch : stri)
        {
            if (ch == '(')
            {
                acount++;
            }
            else
            {
                bcount++;
                if (bcount > acount)
                {
                    acount = 0;
                    bcount = 0;
                }
                else if (bcount != 0 && acount == bcount)
                {
                    // cout << bcount << endl;
                    frontCount = max(frontCount, 2 * min(acount, bcount));
                }
            }
        }

        int n = stri.size();
        acount = 0;
        bcount = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            char ch = stri[i];
            if (ch == ')')
            {
                acount++;
            }
            else
            {
                bcount++;
                if (bcount > acount)
                {
                    acount = 0;
                    bcount = 0;
                }
                else if (bcount != 0 && acount == bcount)
                {
                    backCount = max(backCount, 2 * min(acount, bcount));
                }
            }
        }

        return max(frontCount, backCount);
    }
};