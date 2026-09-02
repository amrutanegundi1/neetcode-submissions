class Solution {
public:
    map<tuple<bool,int,int>, int> mp;
    int stoneGameII(vector<int>& piles) {
        return dfs(piles, 0, 1, true);
    }

    int dfs(vector<int>& piles, int i, int m, bool alice)
    {
        if(i >= piles.size())
        {
            return 0;
        }
        if(mp.find({alice,i,m}) != mp.end())
        {
            return mp[{alice,i,m}];
        }
        int res = 0;
        if(!alice)
            res = INT_MAX;
        int size = 2 * m;
        for(int j = 0; j < size; j++)
        {
            int stones = 0;
            for(int k = 0; k <= j; k++)
            {
                if(i + k < piles.size())
                    stones += piles[i+k];
            }
            if(alice)
            {
                res = max(res, stones + dfs(piles, i + j + 1, max(m, j+1), !alice));
            }
            else
            {
                res = min(res, dfs(piles, i + j + 1, max(m, j+1), !alice));
            }
        }
        mp[{alice,i,m}] = res;
        return res;
    }

};