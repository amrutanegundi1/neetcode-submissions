class Solution {
public:
    map<pair<int,bool>, int> mp;
    int res = 0;
    int maxProfit(vector<int>& prices) {
        dfs(prices, true, 0);
        return res;
    }
    int dfs(vector<int>& prices, bool buy, int i)
    {
        if(i >= prices.size())
        {
            return 0;
        }

        if(mp.find(pair<int,bool>(i, buy)) != mp.end())
        {
            return mp[pair<int,bool>(i, buy)];
        }

        //do not do anything today
        int res1 = dfs(prices, buy, i+1);
        int res2 = 0, res3 = 0;
        if(buy)
        {
            res2 = dfs(prices, false, i + 1) - prices[i];
            mp[pair<int,bool>(i, buy)] = max(res1, res2);
            res = max(res, mp[pair<int,bool>(i, buy)]);
            return max(res1, res2);
        }
        else
        {
            res3 = dfs(prices, true, i + 1) + prices[i];
            mp[pair<int,bool>(i, buy)] = max(res1, res3);
            return max(res1, res3);
        }

    }
};