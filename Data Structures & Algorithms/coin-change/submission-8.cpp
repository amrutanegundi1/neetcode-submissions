class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // int res = dfs(coins,amount,0);
        // if(res == INT_MAX)
        //     return -1;
        // return res;

        vector<int> res = vector<int>(amount+1, INT_MAX);
        res[0] = 0;

        for(int i = 1; i <= amount; i++)
        {
            for(int j = 0; j < coins.size(); j++)
            {
                if(coins[j] <= i && res[i-coins[j]] != INT_MAX)
                {
                    res[i] = min(res[i], 1 + res[i-coins[j]]);
                }
            }
        }
        if(res[amount] == INT_MAX)
            return -1;
        return res[amount];

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
