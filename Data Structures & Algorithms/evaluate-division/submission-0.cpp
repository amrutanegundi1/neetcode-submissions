class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        unordered_map<string, vector<pair<string, double>>> adj;

        for(int i = 0; i <  equations.size(); i++)
        {
            string s1 = equations[i][0];
            string s2 = equations[i][1];
            double value = values[i];

            adj[s1].push_back({s2, value});
            adj[s2].push_back({s1, 1/value});
        }
        vector<double> res;
        for(auto itr : queries)
        {
            res.push_back(bfs(itr[0], itr[1], adj));
        }
        return res;
    }

    double bfs(string src, string dst, unordered_map<string, vector<pair<string, double>>> &adj)
    {
        if(adj.find(src) == adj.end() || adj.find(dst) == adj.end())
        {
            return -1.0;
        }
        queue<pair<string, double>> que;
        que.push({src, 1.0});
        unordered_set<string> visit;
        while(!que.empty())
        {
            pair<string, double> pr = que.front();
            que.pop();
            if(pr.first == dst)
            {
                return pr.second;
            }
            visit.insert(pr.first);
            for(int i = 0; i < adj[pr.first].size(); i ++)
            {
                if(visit.find(adj[pr.first][i].first) == visit.end())
                {
                    double weight = pr.second * adj[pr.first][i].second;
                    que.push({adj[pr.first][i].first, weight});
                }
            }

        }
        return -1.0;
    }

};