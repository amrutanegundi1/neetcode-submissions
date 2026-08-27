class Solution {
public:
    set<pair<int,int>> visited;
    int islandPerimeter(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1 && visited.find({i, j}) == visited.end())
                {
                    return dfs(i, j, grid);
                }
            }
        }
        return 0;
    }
    int dfs(int i, int j, vector<vector<int>>& grid)
    {
        if(visited.find({i, j}) != visited.end())
        {
            return 0;
        }
        if(i < 0 || i == grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
        {
            return 1;
        }
        visited.insert({i, j});
        int sum = 0;
        sum += dfs(i+1, j, grid);
        sum += dfs(i-1, j, grid);
        sum += dfs(i, j+1, grid);
        sum += dfs(i, j-1, grid);
        return sum;
    }
};