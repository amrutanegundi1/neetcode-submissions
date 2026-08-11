class Solution {
   public:
    map<pair<int, bool>, int> mp;
    int maxProfit(vector<int>& prices) {
        return dfs(prices, true, 0);
    }
    int dfs(vector<int>& prices, bool buy, int i) {
        if (i >= prices.size()) {
            return 0;
        }

        if (mp.find(pair<int, bool>(i, buy)) != mp.end()) {
            return mp[pair<int, bool>(i, buy)];
        }

        // do not do anything today
        int res1 = dfs(prices, buy, i + 1);
        int res2 = 0, res3 = 0;
        if (buy) {
            res2 = dfs(prices, false, i + 1) - prices[i];
        } else {
            res3 = dfs(prices, true, i + 1) + prices[i];
        }
        mp[pair<int, bool>(i, buy)] = max(res1, max(res2, res3));
        return mp[pair<int, bool>(i, buy)];
    }
};