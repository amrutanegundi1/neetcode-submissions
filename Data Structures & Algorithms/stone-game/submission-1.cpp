struct HASH
{
    size_t operator()(const pair<int,int>& pr) const
    {
        return (static_cast<size_t>(pr.first) << 32) | (static_cast<size_t>(pr.second));
    }

};
class Solution {
public:
    unordered_map<pair<int,int>, int, HASH> mp;
    bool stoneGame(vector<int>& piles) {
        int aliceSum = dfs(piles, 0, piles.size()-1);
        int total = 0;
        for(auto itr : piles)
        {
            total += itr;
        }
        return (aliceSum > (total - aliceSum));
    }

    int dfs(vector<int>& piles, int l, int r)
    {
        if(l > r)
        {
            return 0;
        }
        if(mp.find({l, r}) != mp.end())
        {
            return mp[{l, r}];
        }
        int left = piles[l];
        int right = piles[r];
        mp[{l, r}] = max(left + max(dfs(piles, l+2, r), dfs(piles, l+1, r-1)), right + max(dfs(piles, l+1, r-1), dfs(piles, l, r-2)));
        return mp[{l, r}];
    }
};