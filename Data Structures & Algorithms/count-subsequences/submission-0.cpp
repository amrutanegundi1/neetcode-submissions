class Solution {
public:
    map<pair<int,int>, int> mp;
    int slen = 0, tlen = 0;
    int numDistinct(string s, string t) {
        slen = s.length();
        tlen = t.length();
        return dfs(0, 0, s, t);
    }
    int dfs(int i, int j, string s, string t)
    {
        if(j == tlen)
        {
            return 1;
        }
        if(i == slen)
        {
            return 0;
        }
        if(mp.find(pair<int,int>(i,j)) != mp.end())
        {
            return mp[pair<int,int>(i,j)];
        }
        int res;
        if(s[i] == t[j])
        {
            res = dfs(i+1, j+1, s, t) + dfs(i+1, j, s, t);
        }
        else
        {
            res = dfs(i+1, j, s, t);
        }
        mp[pair<int,int>(i,j)] = res;
        return res;
    }
};
