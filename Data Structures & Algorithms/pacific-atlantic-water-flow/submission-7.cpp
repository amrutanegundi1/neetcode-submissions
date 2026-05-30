class Solution {
public:
    int ROWS, COLS;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = heights.size();
        COLS = heights[0].size();
        vector<vector<int>> res;
        set<pair<int,int>> pacific, atlantic;

        for(int i =0; i < ROWS; i++)
        {
            dfs(heights, i, 0, heights[i][0], pacific);
            dfs(heights, i, COLS-1, heights[i][COLS-1], atlantic);
        }

        for(int i =0; i < COLS; i++)
        {
            dfs(heights, 0, i, heights[0][i], pacific);
            dfs(heights, ROWS-1, i, heights[ROWS-1][i], atlantic);
        }

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                pair<int,int> toCheck(r, c);
                if(pacific.find(toCheck) != pacific.end() && atlantic.find(toCheck) != atlantic.end())
                {
                    res.push_back({r,c});
                }
            }
        }

        return res;
    }

    void dfs(vector<vector<int>>& heights, int r, int c, int prevVal, set<pair<int,int>> &visited) {
        if (r < 0 || c < 0 || r >= ROWS || c >= COLS || visited.find(pair<int,int>(r,c)) != visited.end() || prevVal > heights[r][c]) {
            return;
        }
        visited.insert(pair<int,int>(r,c));
        for (auto& dir : directions) {
            dfs(heights, r + dir[0], c + dir[1], heights[r][c], visited);
        }
    }
};