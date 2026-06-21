class Solution {
public:
    set<int> visited;
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
        if(p.find(i) == p.end())
        {
            if(find(res.begin(), res.end(), i) == res.end())
                res.push_back(i);
            return true;
        }
        if(visited.find(i) != visited.end())
            return false;

        visited.insert(i);
        for(int j = 0; j < p[i].size(); j++)
        {
            if(!dfs(p[i][j]))
            {
                return false;
            }
        }
        visited.erase(i);
        if(find(res.begin(), res.end(), i) == res.end())
                res.push_back(i);
        p[i] = {};
        return true;
    }
};
