class Solution {
   public:
    map<pair<int, bool>, int> mp;
    int maxProfit(vector<int>& prices) { return dfs(0, true, prices); }
    int dfs(int i, bool buying, vector<int>& prices) {
        if (i >= prices.size()) {
            return 0;
        }
        // pair<int, bool> pr = pair<int, bool>(i, buying);
        // if (mp.find(pr) != mp.end()) {
        //     return mp[pr];
        // }
        // int cooldown = dfs(i + 1, buying, prices);
        // if (buying) {
        //     int buy = dfs(i + 1, false, prices) - prices[i];
        //     mp[pr] = max(buy, cooldown);
        // } else {
        //     int sell = dfs(i + 2, true, prices) + prices[i];
        //     mp[pr] = max(sell, cooldown);
        // }
        // return mp[pr];
        pair<int,bool> pr = pair<int,bool>(i, buying);
        if(mp.find(pr) != mp.end())
        {
            return mp[pr];
        }
        if(buying)
        {
            int res = max(dfs(i+1, buying, prices), dfs(i+1, false, prices) -prices[i]);
            
            mp[pr] = res;
            return res;
        }
        else
        {
            int res = max(prices[i] + dfs(i+2, true, prices), dfs(i+1, buying, prices));
            mp[pr] = res;
            return res;
        }


    }
};
