class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        int res = 0;
        for(auto itr : times)
        {
            adj[itr[0]].push_back(pair<int,int>(itr[1], itr[2]));
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> que;
        que.push(pair<int,int>(0,k));
        unordered_set<int> visited;
        while(!que.empty())
        {
            pair<int,int> pr = que.top();
            que.pop();
            if(visited.find(pr.second) != visited.end())
            {
                continue;
            }
            visited.insert(pr.second);
            res = max(res, pr.first);
            for(auto itr : adj[pr.second])
            {
                que.push(pair<int,int>(pr.first + itr.second, itr.first));
            }
        }

        if(visited.size() == n)
        {
            return res;
        }
        return -1;
    }
};
