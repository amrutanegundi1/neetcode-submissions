class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> raddj(k+1);
        for(auto itr : rowConditions)
        {
            raddj[itr[0]].push_back(itr[1]);
        }

        vector<vector<int>> caddj(k+1);
        for(auto itr : colConditions)
        {
            caddj[itr[0]].push_back(itr[1]);
        }
        vector<int> rowOrder, colOrder;
        unordered_map<int, bool> visited;
        for(int i = 1; i <= k; i++)
        {
            if(dfs(raddj, i, rowOrder, visited))
            {
                return {};
            }
        }
        visited.clear();

        for(int i = 1; i <= k; i++)
        {
            if(dfs(caddj, i, colOrder, visited))
            {
                return {};
            }
        }
        reverse(rowOrder.begin(), rowOrder.end());
        reverse(colOrder.begin(), colOrder.end());
        // for(auto itr : rowOrder)
        // {
        //     cout<<itr<<" ";
        // }
        // cout<<endl;

        // for(auto itr : colOrder)
        // {
        //     cout<<itr<<" ";
        // }
        // cout<<endl;

        vector<vector<int>> res(k, vector<int>(k, 0));

        for(int i =0; i < k; i++)
        {
            int val = rowOrder[i], colIdx;
            for(int j = 0; j < k; j++)
            {
                if(colOrder[j] == val)
                {
                    colIdx = j;
                    break;
                }
            }
            res[i][colIdx] = val;
        }
        return res;
    }

    bool dfs(vector<vector<int>> &adj, int i, vector<int> &order, unordered_map<int, bool> &v)
    {
        if(v.find(i) != v.end())
        {
            return v[i];
        }
        v[i] = true;
        for(auto itr : adj[i])
        {
            if(dfs(adj, itr, order, v))
            {
                return true;
            }
        }
        order.push_back(i);
        v[i] = false;
        return false;
    }
};