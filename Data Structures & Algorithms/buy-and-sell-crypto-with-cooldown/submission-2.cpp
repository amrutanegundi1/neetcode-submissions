class Solution {
public:
    map<pair<int,bool>, int> mp;
    int maxProfit(vector<int>& prices) {

        return dfs(0, true, prices);
        
    }
    int dfs(int i, bool buying, vector<int>& prices)
    {
        if(i >= prices.size())
        {
            return 0;
        }
        pair<int,bool> pr = pair<int,bool>(i, buying);
        if(mp.find(pr) != mp.end())
        {
            return mp[pr];
        }

        if(buying)
        {
            int buy = dfs(i + 1, false, prices) - prices[i];
            int cooldown = dfs(i + 1, true, prices);
            mp[pr] = max(buy, cooldown);
            return mp[pr];
        }
        else
        {
            int cooldown = dfs(i + 1, false, prices);
            int sell = dfs(i + 2, true, prices) + prices[i];
            mp[pr] = max(sell, cooldown);
            return mp[pr];

        }
    }
};
