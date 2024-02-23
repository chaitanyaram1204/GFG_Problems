class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(3, vector<int>(3, 0)));

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int numTran = 0; numTran <= 2; numTran++)
            {
                for (int haveStock = 0; haveStock <= 1; haveStock++)
                {
                    if (haveStock)
                    {
                        dp[ind][numTran][haveStock] = max(prices[ind] + dp[ind + 1][numTran][0], dp[ind + 1][numTran][1]);
                    }
                    else
                    {
                        if (numTran > 0)
                        {
                            dp[ind][numTran][haveStock] = max(-prices[ind] + dp[ind + 1][numTran - 1][1], dp[ind + 1][numTran][0]);
                        }
                    }
                }
            }
        }
        return dp[0][2][0];
    }
};