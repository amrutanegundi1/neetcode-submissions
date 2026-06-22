class Solution {
public:
    map<pair<int, int>, bool> mp;
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length() != s1.length() + s2.length())
        {
            return false;
        }
        return dfs(0, 0, s1, s2, s3);
    }
    bool dfs(int i1, int j1, string s1, string s2, string s3)
    {
        pair<int, int> pr = pair<int, int>(i1, j1);
        if(mp.find(pr) != mp.end())
        {
            return mp[pr];
        }
        if(i1 == s1.length() && j1 == s2.length())
        {
            return true;
        }
        if(s3[i1+j1] == s1[i1])
        {
            if(dfs(i1+1, j1, s1,s2,s3))
            {
                mp[pr] = true;
                return true;
            }
        }
        if(s3[i1+j1] == s2[j1])
        {
            if(dfs(i1, j1+1, s1,s2,s3))
            {
                mp[pr] = true;
                return true;
            }
        }
        mp[pr] = false;
        return false;
    }
};
