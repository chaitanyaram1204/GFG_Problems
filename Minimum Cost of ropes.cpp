class Solution
{
public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long> &arr)
    {
        priority_queue<long long int, vector<long long int>, greater<int>> pq;
        long long maxi = 0;
        for (auto it : arr)
            pq.push(it);
        while (pq.size() > 1)
        {
            int first = pq.top();
            pq.pop();

            int second = pq.top();
            pq.pop();

            maxi += (first + second);

            pq.push(first + second);
        }
        return maxi;
    }
};