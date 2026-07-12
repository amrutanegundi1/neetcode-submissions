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
};
