class Solution {
public:
    int comb = 0;
    map<pair<int,int>, int> mp;
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1,0));
        for(int i = 0; i < coins.size(); i++)
        {
            dp[i][0] = 1;
        }
        for(int i =1; i<= amount; i++)
        {
            int j = i - coins[0];
            if(j >= 0)
            {
                dp[0][i] = dp[0][j];
            }
        }
        for(int i = 1; i < coins.size(); i++)
        {
            for(int j =1; j <= amount; j++)
            {
                dp[i][j] = dp[i-1][j];
                if(j - coins[i] >= 0)
                {
                    dp[i][j] += dp[i][j-coins[i]];
                }
            }
        }
        // for(int i = 0; i < coins.size(); i++)
        // {
        //     for(int j =0; j <= amount; j++)
        //     {
        //         cout<<dp[i][j]<<" "; 
        //     }
        //     cout<<endl;
        // }
        return dp[coins.size()-1][amount];

    }

    int dfs(int index, int amount, vector<int>& coins)
    {
        if(amount < 0 || index >= coins.size())
        {
            return 0;
        }
        if(amount == 0)
        {
            return 1;
        }
        if(mp.find(pair<int,int>(index, amount)) != mp.end())
        {
            return mp[pair<int,int>(index, amount)];
        }

        //include the element
        mp[pair<int,int>(index, amount)] = dfs(index, amount - coins[index], coins) +
        dfs(index +1, amount, coins);
        return mp[pair<int,int>(index, amount)];
    }
};
