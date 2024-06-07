class Solution
{
public:
    // l and r are input array
    // maxx : maximum in r[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in l[] and r[]
    // Function to find the maximum occurred integer in all ranges.
    int maxOccured(int n, int l[], int r[], int maxx)
    {

        unordered_map<int, int> x;
        unordered_map<int, int> y;
        vector<int> ans(maxx + 1, 0);
        int answer = 0;
        int occ = 0;
        for (int i = 0; i < n; i++)
        {
            x[l[i]]++;
            y[r[i]]--;
        }
        int count = 0;
        for (int i = 0; i <= maxx; i++)
        {
            if (x.find(i) != x.end())
                count += x[i];
            ans[i] = count;
            if (y.find(i) != y.end())
                count += y[i];
        }
        for (int i = 0; i <= maxx; i++)
        {
            if (ans[i] > occ)
            {
                occ = ans[i];
                answer = i;
            }
        }
        return answer;
    }
};