class Solution
{
public:
    int maximumProfit(vector<int> &prices)
    {
        // code here
        int n = prices.size();

        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int i = 0; i < n; ++i)
        {
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }

        return maxProfit;
    }
};