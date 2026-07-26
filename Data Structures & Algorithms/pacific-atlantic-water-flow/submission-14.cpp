class Solution {
public:
    vector<vector<int>> pv, av, res;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        pv.resize(heights.size(), vector<int>(heights[0].size(), 0));
        av.resize(heights.size(), vector<int>(heights[0].size(), 0));

        for(int i =0; i < heights.size(); i++)
        {
            dfs(i, 0, heights, pv, INT_MIN);
            dfs(i, heights[0].size()-1, heights, av, INT_MIN);
        }

        for(int i =0; i < heights[0].size(); i++)
        {
            dfs(0, i, heights, pv, INT_MIN);
            dfs(heights.size()-1, i, heights, av, INT_MIN);
        }

        for(int i = 0; i < heights.size(); i++)
        {
            for(int j = 0; j < heights[0].size(); j++)
            {
                if(pv[i][j] == 1 && av[i][j] == 1)
                {
                    res.push_back(vector<int>{i,j});
                }
            }
        }
        return res;
    }

    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<int>>& visited, int prev)
    {
        if(r < 0 || r >= heights.size() || c < 0 || c >= heights[0].size() || visited[r][c] == 1 || prev > heights[r][c])
        {
            return;
        }
        visited[r][c] = 1;
        dfs(r+1, c, heights, visited, heights[r][c]);
        dfs(r-1, c, heights, visited, heights[r][c]);
        dfs(r, c+1, heights, visited, heights[r][c]);
        dfs(r, c-1, heights, visited, heights[r][c]);
    }
};
