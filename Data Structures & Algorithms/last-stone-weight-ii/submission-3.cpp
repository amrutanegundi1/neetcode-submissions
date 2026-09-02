class Solution {
public:
    map<pair<int,int>, int> mp;
    int lastStoneWeightII(vector<int>& stones) {
        int ssum = 0;
        for(auto itr : stones)
        {
            ssum += itr;
        }

        return dfs(stones, 0, 0, ssum/2, ssum);
    }
    int dfs(vector<int>& stones, int i, int curr, int tar, int total)
    {
        if(curr >= tar || i == stones.size())
        {
            return abs((curr - (total -curr)));
        }
        if(mp.find({i, curr}) != mp.end())
        {
            return mp[{i, curr}];
        }
        mp[{i, curr}] = min(dfs(stones, i+1, curr, tar, total), dfs(stones, i+1, curr + stones[i], tar, total)); 
        return mp[{i, curr}];
    }
};