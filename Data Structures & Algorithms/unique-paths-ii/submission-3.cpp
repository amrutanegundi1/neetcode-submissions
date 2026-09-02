class Solution {
public:
    vector<vector<int>> dp;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        dp.resize(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), INT_MIN));
        if(obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1] == 1)
        {
            return 0;
        }
        return dfs(obstacleGrid, 0, 0);
    }

    int dfs(vector<vector<int>>& grid, int r, int c)
    {
        if(r == grid.size()-1 && c == grid[0].size()-1)
        {
            return 1;
        }

        if(r >= grid.size() || c >= grid[0].size() || grid[r][c] == 1)
        {
            return 0;
        }
        if(dp[r][c] != INT_MIN)
        {
            return dp[r][c];
        }
        dp[r][c] = dfs(grid, r+1, c) + dfs(grid, r, c+1);
        return dp[r][c];
    }
};