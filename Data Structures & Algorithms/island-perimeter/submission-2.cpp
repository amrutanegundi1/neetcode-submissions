class Solution {
public:
    vector<vector<bool>> visited;
    int islandPerimeter(vector<vector<int>>& grid) {
        visited.resize(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1 && visited[i][j] == false)
                {
                    return dfs(i, j, grid);
                }
            }
        }
        return 0;
    }
    int dfs(int i, int j, vector<vector<int>>& grid)
    {
        if(i < 0 || i == grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
        {
            return 1;
        }
        if(visited[i][j])
        {
            return 0;
        }
        visited[i][j] = true;
        int sum = 0;
        sum += dfs(i+1, j, grid);
        sum += dfs(i-1, j, grid);
        sum += dfs(i, j+1, grid);
        sum += dfs(i, j-1, grid);
        return sum;
    }
};