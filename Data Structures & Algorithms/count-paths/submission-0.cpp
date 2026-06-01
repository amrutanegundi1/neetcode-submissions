class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<vector<int>> res(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 || j == 0)
                {
                    res[i][j] = 1;
                }
                else
                {
                    res[i][j] = res[i][j-1] + res[i-1][j];
                }
            }
        }
        return res[m-1][n-1];
    }
};
