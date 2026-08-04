class Solution {
   public:
    map < int, vector<int>> adj;
    vector<int> res;
    map<int, bool> visited;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for (auto itr : prerequisites) {
            adj[itr[0]].push_back(itr[1]);
        }

        for(int i = 0; i < numCourses; i++)
        {
            if(dfs(i))
            {
                return {};
            }
        }
        return res;
    }
    bool dfs(int i)
    {
        if(visited.find(i) != visited.end())
        {
            return visited[i];
        }

        visited[i] = true;
        for(auto itr : adj[i])
        {
            if(dfs(itr))
            {
                return true;
            }
        }
        visited[i] = false;
        res.push_back(i);
        return false;
    }
};
