class Solution {
public:
    int comb = 0;
    map<pair<int,int>, int> mp;
    int change(int amount, vector<int>& coins) {
        return dfs(0, amount, coins);
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
