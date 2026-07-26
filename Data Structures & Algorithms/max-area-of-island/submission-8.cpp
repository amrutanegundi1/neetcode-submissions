class Solution {
   public:
    int res = 0;
    set<pair<int, int>> visited;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        visited.clear(); // Fixes the multi-testcase bug
        res = 0;         // Reset the maximum result too
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1 && visited.find(pair<int, int>(i,j)) == visited.end())
                {
                    int curr = 0;
                    dfs(grid, i, j, curr);
                    res = max(res, curr);
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, int &curr) {
        if (i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0) {
            return;
        }
        pair<int, int> pr(i, j);
        if (grid[i][j] == 0 || visited.find(pr) != visited.end()) {
            return;
        }

        visited.insert(pr);
        curr++;
        
        dfs(grid, i + 1, j, curr);
        dfs(grid, i - 1, j, curr);
        dfs(grid, i, j + 1, curr);
        dfs(grid, i, j - 1, curr);
        
        
    }
};
