class Solution
{
public:
    void nearlySorted(vector<int> &arr, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i <= k; i++)
        {
            pq.push(arr[i]);
        }
        for (int i = k + 1; i < arr.size(); i++)
        {
            arr[i - k - 1] = pq.top();
            pq.pop();
            pq.push(arr[i]);
        }

        int ind = arr.size() - k - 1;
        while (!pq.empty())
        {
            arr[ind++] = pq.top();
            pq.pop();
        }
    }
};