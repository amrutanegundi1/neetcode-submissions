class Solution {
public:
    map<string, vector<string>> adj;
    vector<string> res;
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        sort(tickets.begin(), tickets.end());
        
        for(auto itr : tickets)
        {
            adj[itr[0]].push_back(itr[1]);
        }
        res.push_back("JFK");
        dfs("JFK", tickets);
        return res;
    }
    bool dfs(string node, vector<vector<string>>& tickets)
    {
        if(res.size() == tickets.size() + 1)
        {
            cout<<"true"<<endl;
            return true;
        }
        if(adj.find(node) == adj.end() || adj[node].size() == 0)
        {
            return false;
        }
        vector<string> temp = adj[node];
        for(int i = 0; i < temp.size(); i++)
        {
            string v = temp[i];
            res.push_back(v);
            adj[node].erase(adj[node].begin()+i);
            if(dfs(v, tickets))
            {
                return true;
            }
            res.pop_back();
            adj[node].insert(adj[node].begin()+i, v);
        }
        return false;
    }
};
