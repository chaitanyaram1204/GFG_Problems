class Solution {
  public:
    int findCoverage(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == 0)
                {
                    if(i >= 1)
                    {
                        count += matrix[i-1][j];
                    }
                    if(i < n-1)
                    {
                        count += matrix[i+1][j];
                    }
                    if(j >= 1)
                    {
                        count += matrix[i][j-1];
                    }
                    if(j < m-1)
                    {
                        count += matrix[i][j+1];
                    }
                }
            }
        }
        return count;
    }
};