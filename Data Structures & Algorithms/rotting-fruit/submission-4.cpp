class Solution {
   public:
    queue<pair<int, int>> q;
    set<pair<int,int>> visit;
    int orangesRotting(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push(pair<int, int>(i, j));
                    visit.insert(pair<int, int>(i, j));
                }
            }
        }
        int minute = 0;

        while (!q.empty()) {
            for (int i = q.size() - 1; i >= 0; i--) {
                pair<int, int> pr = q.front();
                q.pop();
                grid[pr.first][pr.second] = 2;
                addN(grid, pr.first + 1, pr.second);
                addN(grid, pr.first - 1, pr.second);
                addN(grid, pr.first, pr.second + 1);
                addN(grid, pr.first, pr.second - 1);
            }
            minute += 1;
        }
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return max(0, minute-1);
    }
    void addN(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1 ||
            visit.find(pair<int, int>(i, j)) != visit.end())
            return;
        q.push(pair<int, int>(i, j));
        visit.insert(pair<int, int>(i, j));
    }
};
