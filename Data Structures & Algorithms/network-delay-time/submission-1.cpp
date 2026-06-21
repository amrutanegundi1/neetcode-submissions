class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto itr : times) {
            adj[itr[0]].push_back(pair<int, int>(itr[1], itr[2]));
        }
        unordered_set<int> visit;
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> que;
        que.push(pair<int, int>(0, k));
        int res = 0;

        while (!que.empty()) {
            pair<int, int> tp = que.top();
            que.pop();
            cout<<tp.first<<" "<<tp.second<<endl;
            if (visit.find(tp.second) != visit.end()) {
                continue;
            }
            visit.insert(tp.second);
            res = max(res, tp.first);

            for(auto itr : adj[tp.second])
            {
                if(visit.find(itr.first) != visit.end())
                {
                    continue;
                }
                que.push(pair<int, int>(tp.first + itr.second, itr.first));
            }
        }

        if(visit.size() == n)
            return res;
        return -1;
    }

    void dfs(int node, unordered_map<int, int>& visited, vector<vector<pair<int, int>>>& adj) {
        for (auto itr : adj[node]) {
            if (visited.find(itr.first) != visited.end()) {
                if (visited[itr.first] > itr.second) {
                    visited[itr.first] = itr.second;
                }
            } else {
                if (visited.find(node) != visited.end()) {
                    visited[itr.first] = itr.second + visited[node];
                } else {
                    visited[itr.first] = itr.second;
                }
            }
            dfs(itr.first, visited, adj);
        }
    }
};
