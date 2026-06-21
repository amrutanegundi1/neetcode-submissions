class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> adj(edges.size()+1);

        for(auto itr : edges)
        {
            adj[itr[0]].push_back(itr[1]);
            adj[itr[1]].push_back(itr[0]);
            unordered_set<int> visited;
            if(dfs(itr[0], -1, visited, adj))
            {
                return itr;
            }

        }
        return vector<int>{};      
    }

    bool dfs(int node, int parent, unordered_set<int> visited, vector<vector<int>> &adj)
    {
        if(visited.find(node) != visited.end())
        {
            return true;
        }

        visited.insert(node);

        for(auto itr : adj[node])
        {
            if(itr == parent)
            {
                continue;
            }
            else if(dfs(itr, node, visited, adj))
            {
                return true;
            }
        }
        return false;
    }

};
