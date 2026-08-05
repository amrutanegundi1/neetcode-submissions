class Solution {
public:
    set<int> visited;
    bool validTree(int n, vector<vector<int>>& edges) {


        if(n == 0)
            return true;

        unordered_map<int, vector<int>> mp;

        for(auto itr : edges)
        {
            mp[itr[0]].push_back(itr[1]);
            mp[itr[1]].push_back(itr[0]);
        }

        

        bool ret = dfs(0, -1, mp);

        return ret && visited.size() == n;

    }
    bool dfs(int i, int prev, unordered_map<int, vector<int>>& mp)
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
                if(!dfs(itr, i, mp))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
