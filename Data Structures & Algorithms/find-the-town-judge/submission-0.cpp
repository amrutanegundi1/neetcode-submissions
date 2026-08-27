class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> adj(n+1, vector<int>({}));
        for(auto itr : trust)
        {
            adj[itr[0]].push_back(itr[1]);
        }
        for(int i = 1; i <= n; i++)
        {
            if(adj[i].size() == 0)
            {
                bool found = true;
                for(int j = 1; j <= n; j++)
                {
                    if(i != j)
                    {
                        if(!std::ranges::contains(adj[j], i))
                        {
                            found = false;
                            break;
                        }
                    }
                }
                if(found)
                {
                    return i;
                }
            }
        }
        return -1;
    }
};