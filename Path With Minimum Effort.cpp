class Solution
{
public:
    bool check(vector<vector<int>> &a, int mid)
    {
        int m = a.size();
        int n = a[0].size();
        vector<int> xdir{0, 0, 1, -1};
        vector<int> ydir{1, -1, 0, 0};
        bool visited[m][n];
        memset(visited, false, sizeof(visited));
        visited[0][0] = true;
        queue<pair<int, int>> q;
        q.push({0, 0});
        while (q.empty() == false)
        {
            auto curr = q.front();
            q.pop();
            int x = curr.first;
            int y = curr.second;
            if (x == m - 1 && y == n - 1)
            {
                return true;
            }
            for (int k = 0; k < 4; k++)
            {
                int newX = x + xdir[k];
                int newY = y + ydir[k];
                if (newX >= 0 && newY >= 0 && newX < m && newY < n && visited[newX][newY] == false && abs(a[x][y] - a[newX][newY]) <= mid)
                {
                    visited[newX][newY] = true;
                    q.push({newX, newY});
                }
            }
        }
        return false;
    }

public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights)
    {
        int low = 0;
        int high = 1e6;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (check(heights, mid))
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};