class Solution
{
public:
    void dfs(int node, vector<int> &visited, vector<int> adj[])
    {
        visited[node] = 1;
        for (auto neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                dfs(neighbor, visited, adj);
            }
        }
    }

    bool isCircle(vector<string> &words)
    {
        vector<int> adj[26];                           // Adjacency list for each letter
        vector<int> inDegree(26, 0), outDegree(26, 0); // In-degree and out-degree arrays
        vector<int> visited(26, 0);                    // Visited array for DFS
        int startNode = -1;

        // Build the adjacency list and track in-degrees and out-degrees
        for (auto word : words)
        {
            char first = word[0];
            char last = word[word.length() - 1];

            adj[first - 'a'].push_back(last - 'a');
            outDegree[first - 'a']++;
            inDegree[last - 'a']++;

            startNode = first - 'a'; // We use this to start the DFS later
        }

        // Check if in-degree and out-degree match for every node
        for (int i = 0; i < 26; i++)
        {
            if (inDegree[i] != outDegree[i])
            {
                return false; // If any node has unequal in/out degrees, it can't form a circle
            }
        }

        // Perform DFS to check if all nodes with non-zero degree are connected
        dfs(startNode, visited, adj);

        // Ensure all nodes involved in the circle are visited
        for (int i = 0; i < 26; i++)
        {
            if ((inDegree[i] > 0) && !visited[i])
            {
                return false; // If any node is unvisited, the graph is not fully connected
            }
        }

        return true; // All conditions for forming a circle are satisfied
    }
};