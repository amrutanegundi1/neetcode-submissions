class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {


        if(n == 0)
            return true;

        unordered_map<int, vector<int>> mp;

        for(auto itr : edges)
        {
            mp[itr[0]].push_back(itr[1]);
            mp[itr[1]].push_back(itr[0]);
        }

        set<int> visited;

        bool ret = dfs(0, -1, visited, mp);

        return ret && visited.size() == n;

    }
    bool dfs(int i, int prev, set<int> &visited, unordered_map<int, vector<int>>& mp)
    {
        if(visited.find(i) != visited.end())
        {
            return false;
        }
        visited.insert(i);
        for(auto itr : mp[i])
        {
            if(itr != prev)
            {
                if(!dfs(itr, i, visited, mp))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
