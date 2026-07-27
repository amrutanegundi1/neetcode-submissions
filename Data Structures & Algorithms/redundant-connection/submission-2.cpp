class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> mp;

        for(auto itr : edges)
        {
            mp[itr[0]].push_back(itr[1]);
            mp[itr[1]].push_back(itr[0]);
            unordered_set<int> visit;
            if(dfs(itr[0], -1, mp, visit))
            {
                return itr;
            }
        }
        return {};
    }
    bool dfs(int i, int prev,unordered_map<int, vector<int>>& mp, unordered_set<int>& visit)
    {

        if(visit.find(i) != visit.end())
        {
            return true;
        }

        visit.insert(i);
        for(auto itr : mp[i])
        {
            if(itr != prev)
            {
                if(dfs(itr, i, mp, visit))
                {
                    return true;
                }
            }
        }
        visit.erase(i);
        return false;
    }
};
