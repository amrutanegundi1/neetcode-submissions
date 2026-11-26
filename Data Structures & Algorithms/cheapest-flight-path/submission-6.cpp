class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> res(n, INT_MAX), temp(n,INT_MAX);

        res[src] = 0;
        temp[src] = 0;

        for(int i = 0; i <= k; i++)
        {
            for(auto itr : flights)
            {
                if(res[itr[0]] != INT_MAX)
                {
                    temp[itr[1]] = min(temp[itr[1]], res[itr[0]] + itr[2]);
                }
            }
            res = temp;
        }
        if(res[dst] == INT_MAX)
        {
            return -1;
        }
        return res[dst];
    }
};
