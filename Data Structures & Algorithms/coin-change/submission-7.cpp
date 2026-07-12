class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int res = dfs(coins,amount,0);
        if(res == INT_MAX)
            return -1;
        return res;
    }

    int dfs(vector<int>& coins, int amount, int ind)
    {
        if(amount == 0)
        {
            return 0;
        }
        if(ind >= coins.size() || amount < 0)
        {
            return INT_MAX;
        }
        
        int res1 = dfs(coins, amount - coins[ind], ind);
        int res2 = dfs(coins, amount, ind+1);
        if(res1 == INT_MAX)
            return res2;
        return min((1 + res1), res2);
    }
};
