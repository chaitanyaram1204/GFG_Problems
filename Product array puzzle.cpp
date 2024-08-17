class Solution
{
public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int> &nums)
    {

        int n = nums.size();
        vector<long long int> ans(n, 1);

        long long int leftProduct = 1;
        for (int i = 0; i < n; i++)
        {
            ans[i] *= leftProduct;
            leftProduct *= nums[i];
        }

        long long int rightProduct = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            ans[i] *= rightProduct;
            rightProduct *= nums[i];
        }
        return ans;
    }
};