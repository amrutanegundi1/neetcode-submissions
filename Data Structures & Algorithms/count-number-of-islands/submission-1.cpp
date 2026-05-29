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
                    bfs(grid,i,j,visited);
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

    void bfs(vector<vector<char>>& grid, int i, int j, set<pair<int,int>> &visited)
    {

        queue<pair<int,int>> que;
        que.push(pair<int,int>(i,j));

        while(!que.empty())
        {
            pair<int,int> curr = que.front();
            que.pop();
            visited.insert(curr);
            vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
            for(auto itr : directions)
            {
                int row = curr.first + itr.first, col = curr.second + itr.second;
                if(row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size())
                {
                    if(grid[row][col] == '1' && visited.find(pair<int,int>(row,col)) == visited.end())
                    {
                        que.push(pair<int,int>(row, col));
                    }
                }
            }
        }
    }
};
