class Solution {
public:
    unordered_map<int, bool> visited;
        vector<int> res;

    vector<int> findOrder(int numCourses, vector<vector<int>>& preq) {
        unordered_map<int, vector<int>> adj;
        for(int i = 0; i < preq.size(); i++)
        {
            adj[preq[i][0]].push_back(preq[i][1]);
        }
        for(int i = 0; i < numCourses; i++)
        {
            if(dfs(i, adj))
            {
                return {};
            }
        }
        return res;
    }
    
    bool dfs(int i, unordered_map<int, vector<int>>& adj)
    {
        if(visited.find(i) != visited.end())
        {
            return visited[i];
        }

        visited[i] = true;
        for(int j = 0; j < adj[i].size(); j++)
        {
            if(dfs(adj[i][j], adj))
            {
                return true;
            }
        }
        visited[i] = false;
        res.push_back(i);
        return false;
    }


};
