class Solution
{
public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto it : arr)
        {
            pq.push(it);
        }
        for (int i = 0; i < k; i++)
        {
            if (i == k - 1)
            {
                return pq.top();
            }
            pq.pop();
        }
    }
};