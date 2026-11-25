class Solution {
public:
    vector<int> res;
    vector<vector<int>> adj;
    vector<int> findOrder(int numCourses, vector<vector<int>>& preq) {
        adj.resize(numCourses);
        for(int i = 0; i < preq.size(); i++)
        {
            adj[preq[i][0]].push_back(preq[i][1]);
        }
        unordered_map<int, bool> visited;
        for(int i = 0; i < numCourses; i++)
        {
            if(dfs(i, visited))
            {
                return {};
            }
        }
        return res;
    }
    bool dfs(int i, unordered_map<int, bool> &visited)
    {
        if(visited.find(i) != visited.end())
        {
            return visited[i];
        }
        visited[i] = true;
        for(auto itr : adj[i])
        {
            if(dfs(itr, visited))
            {
                return true;
            }
        }
        visited[i] = false;
        res.push_back(i);
        return false;
    }
};
