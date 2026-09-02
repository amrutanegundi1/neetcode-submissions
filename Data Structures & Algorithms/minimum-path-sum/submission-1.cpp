class Solution {
public:
    vector<vector<int>> mp;
    int minPathSum(vector<vector<int>>& grid) {
        mp.resize(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        return dfs(grid,0,0);
    }

    int dfs(vector<vector<int>>& grid, int r, int c)
    {
        if(grid.size()-1 == r && grid[0].size()-1 == c)
        {
            return grid[r][c];
        }
        if(r >= grid.size() ||  c >= grid[0].size())
        {
            return INT_MAX;
        }
        if(mp[r][c] != INT_MAX)
        {
            return mp[r][c];
        }
        int s1 = dfs(grid, r+1,c);
        int s2 = dfs(grid, r,c+1);
        mp[r][c] = grid[r][c] + min(s1, s2); 
        return mp[r][c];
    }
};