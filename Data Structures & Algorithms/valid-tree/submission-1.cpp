class Solution {
public:
    unordered_map<int,vector<int>> adj;
    unordered_map<int, bool> visited;
    bool validTree(int n, vector<vector<int>>& edges) {

            for(int i = 0; i < edges.size(); i++)
            {
                adj[edges[i][0]].push_back(edges[i][1]);
                adj[edges[i][1]].push_back(edges[i][0]);
            }
            if(dfs(0, -1) && visited.size() == n)
                return true;
            return false;
    }
    bool dfs(int i, int prev)
    {
        if(visited.find(i) != visited.end() && visited[i] == true)
        {
            return false;
        }
        visited[i] = true;
        for(int j = 0; j < adj[i].size(); j++)
        {
            if(adj[i][j] == prev)
                continue;
            if(!dfs(adj[i][j],i))
            {
                return false;
            }
        }
        visited[i] = false;
        return true;
    }
};
