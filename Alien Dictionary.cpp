class Solution
{
public:
    string findOrder(string dict[], int n, int k)
    {
        vector<int> adj[k];

        for (int i = 0; i < n - 1; i++)
        {
            string first = dict[i];
            string second = dict[i + 1];
            int size = min(first.size(), second.size());
            for (int j = 0; j < size; j++)
            {
                if (first[j] != second[j])
                {
                    adj[first[j] - 'a'].push_back(second[j] - 'a');
                    break;
                }
            }
        }

        vector<int> indegree(k, 0);
        for (int i = 0; i < k; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < k; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        string result = "";

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            result += (node + 'a');

            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        if (result.size() == k)
            return result;
        return "";
    }
};