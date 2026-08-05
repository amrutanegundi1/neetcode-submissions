class Solution {
public:
    unordered_map<int, vector<int>> mp;
    unordered_map<int, bool> visited;
    bool validTree(int n, vector<vector<int>>& edges) {
        for(auto itr : edges)
        {
            mp[itr[0]].push_back(itr[1]);
            mp[itr[1]].push_back(itr[0]);
        }
        if(dfs(0, -1))
        {
            return false;
        }
        return visited.size() == n;
    }

    bool dfs(int i, int prev)
    {
        if(visited.find(i) != visited.end())
            return visited[i];
        visited[i] = true;
        for(auto itr : mp[i])
        {
            if(itr != prev)
            {
                if(dfs(itr, i))
                {
                    return true;
                }
            }
        }
        visited[i] = false;
        return false;
    }
};
