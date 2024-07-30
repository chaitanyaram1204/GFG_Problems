class Solution
{
public:
    vector<pair<char, pair<int, int>>> directions{{'L', {0, -1}}, {'U', {-1, 0}}, {'R', {0, 1}}, {'D', {1, 0}}};
    void dfs(int i, int j, int n, int m, string str, vector<string> &ans, vector<vector<int>> &visit, vector<vector<int>> &matrix)
    {
        if (i == n - 1 && j == m - 1 && matrix[i][j])
        {
            ans.push_back(str);
            return;
        }
        if (i < 0 || j < 0 || i >= n || j >= m || visit[i][j] || !matrix[i][j])
        {
            return;
        }
        visit[i][j] = 1;
        for (auto dire : directions)
        {
            char ch = dire.first;
            int r = i + dire.second.first;
            int c = j + dire.second.second;
            dfs(r, c, n, m, str + ch, ans, visit, matrix);
        }
        visit[i][j] = 0;
    }
    vector<string> findPath(vector<vector<int>> &matrix)
    {
        vector<string> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> visit(n, vector<int>(m, 0));
        dfs(0, 0, n, m, "", ans, visit, matrix);
        return ans;
    }
};