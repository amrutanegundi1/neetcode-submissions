class Solution {
public:
    map<pair<int,int>, int> mp;
    int change(int amount, vector<int>& coins) {
        return dfs(amount, coins, 0);
    }
    int dfs(int amount, vector<int>& coins, int i)
    {
        pair<int, int> pr = pair<int,int>(i, amount);
        if(mp.find(pr) != mp.end())
        {
            return mp[pr];
        }
        if(i >= coins.size() || amount < 0)
        {
            return 0;
        }
        if(amount == 0)
        {
            return 1;
        }

        mp[pr] = dfs(amount, coins, i+1) + dfs(amount-coins[i], coins, i);
        return mp[pr];
    }
};
