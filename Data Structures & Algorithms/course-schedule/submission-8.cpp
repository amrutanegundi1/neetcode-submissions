class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int, vector<int>> preMap;
        set<int> visited;
        for(auto itr : prerequisites)
        {
            preMap[itr[0]].push_back(itr[1]);
        }

        for(int i = 0; i < numCourses; i++)
        {
            if(!dfs(i, visited, preMap))
            {
                return false;
            }
        }
        return true;
    }

    bool dfs(int crs, set<int> &visited, unordered_map<int, vector<int>> &preMap)
    {
        if(visited.find(crs) != visited.end())
        {
            return false;
        }

        if(preMap.find(crs) == preMap.end() || preMap.find(crs)->second.size() == 0)
        {
            return true;
        }

        visited.insert(crs);
        for(auto itr : preMap[crs])
        {
            if(!dfs(itr, visited, preMap))
            {
                return false;
            }
        }
        visited.erase(crs);
        // preMap[crs] = {};
        return true;
    }
    void removeElement(vector<int> &vec, int ele)
    {
        vector<int> res;
        int ind = -1;
        for(int i = 0; i < vec.size(); i++)
        {
            if(vec[i] != ele)
            {
                res.push_back(vec[i]);
            }
        }
        vec = res;
    }
};
