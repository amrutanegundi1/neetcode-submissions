class Solution {
public:
    int rows = 0, cols = 0, res = 0;
    int swimInWater(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> que;
        set<pair<int, int>> visited;

        que.push(pair<int, pair<int,int>>(grid[0][0], pair<int,int>(0,0)));
        visited.insert(pair<int,int>(0,0));
        while(!que.empty())
        {
            pair<int, pair<int,int>> pr = que.top();
            if(pr.second.first == rows - 1 && pr.second.second == cols-1)
            {
                res = max(res, pr.first);
                return res;
            }
            que.pop();
            res = max(res, pr.first);
            addQueue(grid, que, visited, pr.first, pr.second.first + 1, pr.second.second);
            addQueue(grid, que, visited, pr.first, pr.second.first - 1, pr.second.second);
            addQueue(grid, que, visited, pr.first, pr.second.first, pr.second.second + 1);
            addQueue(grid, que, visited, pr.first, pr.second.first, pr.second.second - 1);

        }
        return 0;
        
    }

    void addQueue(vector<vector<int>>& grid, priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> &que,set<pair<int, int>> &visited, int t, int r, int c)
    {
        if(r < 0 || r >= rows || c < 0 || c >= cols || visited.find(pair<int, int>(r,c)) != visited.end())
        {
            return;
        }
        que.push(pair<int, pair<int,int>>(grid[r][c], pair<int,int>(r,c)));
        visited.insert(pair<int, int>(r,c));
    }
};
