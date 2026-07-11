class Solution {
public:
    set<int> visited;
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
            if(!dfs(i))
            {
                return {};
            }
        }
        return res;      
    }
    bool dfs(int i)
    {
        if(cycle.find(i) != cycle.end())
            return false;
        if(visited.find(i) != visited.end())
            return true;
        if(p[i].size() == 0)
        {
            if(visited.find(i) == visited.end())
            {
                visited.insert(i);
                res.push_back(i);
            }
            return true;
        }
        cycle.insert(i);
        for(int j = 0; j < p[i].size(); j++)
        {
            if(!dfs(p[i][j]))
            {
                return false;
            }
        }
        cycle.erase(i);
        if(visited.find(i) == visited.end())
        {
            visited.insert(i);
            res.push_back(i);
        }
        p[i] = {};
        return true;
    }
};
