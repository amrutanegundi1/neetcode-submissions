class Solution {
public:
    unordered_map<int,vector<int>> adj;
    vector<int> res;
    unordered_map<int, bool> visited;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        for(int i = 0; i < prerequisites.size(); i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for(int i = 0; i < numCourses; i++)
        {
            if(dfs(i))
            {
                return vector<int>{};
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
        for(int j = 0; j < adj[i].size(); j++)
        {
            if(dfs(adj[i][j]))
            {
                return true;
            }
        }
        visited[i] = false;
        res.push_back(i);
        return false;
    }

};
