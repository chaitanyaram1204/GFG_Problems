class Solution
{
public:
    bool isvalid(int i, int j, vector<vector<char>> &board, int n)
    {
        int drow = i;
        int dcol = j;

        // left row
        while (i >= 0)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
            i -= 1;
        }

        // left diagonal
        i = drow - 1;
        j = dcol - 1;
        while (i >= 0 && j >= 0)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
            i--;
            j--;
        }

        // down diagonal
        i = drow - 1;
        j = dcol + 1;
        while (j < n && i >= 0)
        {

            if (board[i][j] == 'Q')
            {
                return false;
            }
            i--;
            j++;
        }
        return true;
    }
    void solve(int row, int j, int n, int m, vector<vector<char>> &board, vector<vector<int>> &result)
    {
        if (row == n)
        {
            vector<int> temp;
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (board[i][j] == 'Q')
                    {
                        temp.push_back(j + 1); // Store 1-based column index
                    }
                }
            }
            result.push_back(temp);
            return;
        }

        for (int col = 0; col < n; ++col)
        {
            if (isvalid(row, col, board, n))
            {
                board[row][col] = 'Q';
                solve(row + 1, j, m, n, board, result);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<int>> nQueen(int n)
    {
        vector<vector<int>> result;
        vector<vector<char>> board(n, vector<char>(n, '.'));
        solve(0, 0, n, n, board, result);
        return result;
    }
};