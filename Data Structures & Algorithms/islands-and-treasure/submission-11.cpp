class Solution {
   public:
    set<pair<int, int>> visit;
    queue<pair<int, int>> q;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    q.push(pair<int, int>(i,j));
                }
            }
        }
        int lvl = 0;
        while (!q.empty()) {
            for (int i = q.size() - 1; i >= 0; i--) {
                pair<int, int> pr = q.front();
                q.pop();
                visit.insert(pair<int, int>(pr.first, pr.second));
                grid[pr.first][pr.second] = min(lvl, grid[pr.first][pr.second]);
                addRoom(grid, pr.first + 1, pr.second);
                addRoom(grid, pr.first - 1, pr.second);
                addRoom(grid, pr.first, pr.second + 1);
                addRoom(grid, pr.first, pr.second - 1);
            }
            lvl += 1;
        }
    }
    void dfs(vector<vector<int>>& grid, int i, int j, int curr)
    {
        pair<int,int> pr(i, j);
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == -1 || visit.find(pr) != visit.end())
        {
            return;
        }
        visit.insert(pr);
        grid[i][j] = min(curr, grid[i][j]);
        dfs(grid, i + 1, j, curr+1);
        dfs(grid, i - 1, j, curr+1);
        dfs(grid, i, j - 1, curr+1);
        dfs(grid, i, j + 1, curr+1);
        visit.erase(pr);
    }
    void addRoom(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == -1 ||
            visit.find(pair<int, int>(r, c)) != visit.end())
            return;
        q.push(pair<int, int>(r, c));
        
    }
};
