class Solution {
public:
    map<int, bool> visited;
    set<int> cycle;
    vector<int> res;
    unordered_map<int, vector<int>> p;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        

        for(auto itr : prerequisites)
        {
            p[itr[0]].push_back(itr[1]);
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
        //topological sort, visit is used for cycle detection as well as node is processed or not
        // if present return it, add the node to the result at the end instead of begining

        if(visited.find(i) != visited.end())
            return visited[i];
        visited[i] = true;
        for(int j = 0; j < p[i].size(); j++)
        {
            if(dfs(p[i][j]))
            {
                return true;
            }
        }
        visited[i] = false;
        res.push_back(i);
        p[i] = {};
        return false;
    }
};
