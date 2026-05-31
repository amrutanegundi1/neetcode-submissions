class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> res(amount+1, INT_MAX);
        res[0] = 0;
        cout<<res[amount]<<endl;

        for(int i = 0; i <= amount; i++)
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


};
