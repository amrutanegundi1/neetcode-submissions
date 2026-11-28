class Solution {
public:
    map<pair<int,int>, int> mp;
    int longestCommonSubsequence(string text1, string text2) {
        return dfs(text1, text2, 0, 0);
    }

    int dfs(string t1, string t2, int i, int j)
    {
        if(i == t1.length() || j == t2.length())
        {
            return 0;
        }
        if(mp.find({i,j}) != mp.end())
        {
            return mp[{i,j}];
        }

        if(t1[i] == t2[j])
        {
            mp[{i,j}] = 1 + dfs(t1, t2, i+1, j+1);
        }
        else
        {
            mp[{i,j}] = max(dfs(t1, t2, i+1, j), dfs(t1, t2, i, j+1));
        }
        return mp[{i,j}];
    }
};
