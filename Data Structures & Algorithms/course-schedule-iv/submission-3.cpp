class Solution {
    vector<vector<int>> adj;
    map<pair<int,int>, bool> mp;

public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        adj.assign(numCourses, vector<int>());
        for (auto& pre : prerequisites) {
            adj[pre[0]].push_back(pre[1]);
        }

        vector<bool> res;
        for (auto& query : queries) {
            res.push_back(dfs(query[0], query[1]));
        }
        return res;
    }

private:
    bool dfs(int node, int target) {
        if(mp.find({node,target}) != mp.end())
        {
            return mp[{node,target}];
        }
        if (node == target) return true;
        for (int nei : adj[node]) {
            if (dfs(nei, target)) 
            {
                mp[{node,target}] = true;
                return true;
            }
        }
        mp[{node,target}] = false;
        return false;
    }
};