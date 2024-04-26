class Solution
{
public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>> &matrix)
    {
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 4 directions
        int i = 0, j = 0, direction_ptr = 0;
        vector<int> res;
        while (i >= 0 and i < n and j >= 0 and j < m)
        { // i and j within matrix bounds
            if (matrix[i][j] == 1)
            {
                direction_ptr = (direction_ptr + 1) % 4;
                matrix[i][j] = 0;
            }
            res = {i, j}; // keep last valid i and j
            i = i + directions[direction_ptr][0];
            j = j + directions[direction_ptr][1];
        }
        return res;
    }
};