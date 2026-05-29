class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        set<pair<int,int>> visited;

        int noOfIslands = 0;

        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == '1' && visited.find(pair<int,int>(i,j)) == visited.end())
                {
                    cout<<i<<" "<<j<<endl;
                    noOfIslands++;
                    dfs(grid,i,j,visited);
                }
            }
        }
        return noOfIslands;
    }

    void dfs(vector<vector<char>>& grid, int i, int j, set<pair<int,int>> &visited)
    {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0' || visited.find(pair<int,int>(i,j)) != visited.end())
        {
            return;
        }
        visited.insert(pair<int,int>(i,j));

        dfs(grid, i+1,j,visited);
        dfs(grid, i-1,j,visited);
        dfs(grid, i,j+1,visited);
        dfs(grid, i,j-1,visited);
    }
};
