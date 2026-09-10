class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto itr : times)
        {
            adj[itr[0]].push_back({itr[1], itr[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> que;

        que.push({0, k});
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
            if(visited.size() == n)
            {
                return pr.first;
            }
            for(auto itr : adj[pr.second])
            {
                que.push({pr.first + itr.second, itr.first});
            }
        }
        return -1;
    }
};
