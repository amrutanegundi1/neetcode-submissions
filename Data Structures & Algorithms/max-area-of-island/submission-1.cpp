class Solution {
   public:
    int res = 0;
    set<pair<int, int>> visited;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {

                dfs(grid, i, j);
            }
        }
        return res;
    }

    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0) {
            return 0;
        }
        pair<int, int> pr(i, j);
        if (grid[i][j] == 0 || visited.find(pr) != visited.end()) {
            return 0;
        }

        visited.insert(pr);
        int curr1 = dfs(grid, i + 1, j);
        int curr2 = dfs(grid, i - 1, j);
        int curr3 = dfs(grid, i, j + 1);
        int curr4 = dfs(grid, i, j - 1);
        res = max(res, 1 + curr1 + curr2 + curr3 + curr4);
        return 1 + curr1 + curr2 + curr3 + curr4;
    }
};
