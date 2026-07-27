class Solution {
   public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adj(points.size());
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back(pair<int, int>(j, dist));
                adj[j].push_back(pair<int, int>(i, dist));
            }
        }

        int res = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
        que.push(pair<int, int>(0, 0));

        unordered_set<int> visit;

        while (!que.empty()) {
            pair<int, int> node = que.top();
            que.pop();
            if (visit.find(node.second) != visit.end()) {
                continue;
            }
            visit.insert(node.second);
            res += node.first;
            if(visit.size() == n)
                break;
            for (int i = 0; i < adj[node.second].size(); i++) {
                // if (visit.find(adj[node.second][i].first) != visit.end()) {
                //     continue;
                // }
                que.push(pair<int, int>(adj[node.second][i].second, adj[node.second][i].first));
            }
        }
        return res;
    }
};
