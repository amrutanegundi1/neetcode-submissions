class Solution {
public:
    vector<int> res;
    int minHeight = INT_MAX;
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto itr : edges)
        {
            adj[itr[0]].push_back(itr[1]);
            adj[itr[1]].push_back(itr[0]);
        }
        // for(int i = 0; i < n; i++)
        // {
        //     cout<<i<<"->";
        //     for(int j = 0; j < adj[i].size(); j++)
        //     {
        //         cout<<adj[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        for(int i = 0; i < n; i++)
        {
            int height = bfs(i, adj, n);
            if(height < minHeight)
            {
                minHeight = height;
                res.clear();
                res.push_back(i);
            }
            else if(height == minHeight)
            {
                res.push_back(i);
            }
        }
        return res;
    }

    int bfs(int i, vector<vector<int>>& adj, int n)
    {
        queue<int> que;
        que.push(i);
        int height = 0;
        unordered_set<int> visit;
        while(!que.empty())
        {
            height++;
            for(int j = que.size()-1; j >= 0; j--)
            {
                int tp = que.front();
                que.pop();
                if(visit.find(tp) != visit.end())
                {
                    continue;
                }
                
                visit.insert(tp);
                if(visit.size() == n)
                {
                    return height;
                }
                for(int k = 0; k < adj[tp].size(); k++)
                {
                    que.push(adj[tp][k]);
                }
            }
        }
        return height;
    }
};