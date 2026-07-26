class Solution {
public:
    vector<vector<int>> pc, at, pv, av, res;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        pc.resize(heights.size(), vector<int>(heights[0].size(), 0));
        at.resize(heights.size(), vector<int>(heights[0].size(), 0));
        pv.resize(heights.size(), vector<int>(heights[0].size(), 0));
        av.resize(heights.size(), vector<int>(heights[0].size(), 0));

        for(int i =0; i < heights.size(); i++)
        {
            dfs(i, 0, heights, pc, pv, INT_MIN);
            dfs(i, heights[0].size()-1, heights, at, av, INT_MIN);
        }

        for(int i =0; i < heights[0].size(); i++)
        {
            dfs(0, i, heights, pc, pv, INT_MIN);
            dfs(heights.size()-1, i, heights, at, av, INT_MIN);
        }

        for(int i = 0; i < heights.size(); i++)
        {
            for(int j = 0; j < heights[0].size(); j++)
            {
                if(pc[i][j] == 1 && at[i][j] == 1)
                {
                    res.push_back(vector<int>{i,j});
                }
            }
        }
        return res;
    }

    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<int>>& res, vector<vector<int>>& visited, int prev)
    {
        if(r < 0 || r >= heights.size() || c < 0 || c >= heights[0].size() || visited[r][c] == 1 || prev > heights[r][c])
        {
            return;
        }
        visited[r][c] = 1;
        res[r][c] = 1;
        dfs(r+1, c, heights, res, visited, heights[r][c]);
        dfs(r-1, c, heights, res, visited, heights[r][c]);
        dfs(r, c+1, heights, res, visited, heights[r][c]);
        dfs(r, c-1, heights, res, visited, heights[r][c]);
        visited[r][c] = 0;
    }
};
