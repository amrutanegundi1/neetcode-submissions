class Solution {
public:
    map<pair<int,int>, int> mp;
    int minDistance(string word1, string word2) {
        return dfs(word1, word2, 0, 0);
    }

    int dfs(string word1, string word2, int i1, int j1)
    {
        pair<int,int> pr = pair<int,int>(i1,j1);
        if(mp.find(pr) != mp.end())
        {
            return mp[pr];
        }
        if(i1 == word1.length() && j1 == word2.length())
        {
            return 0;
        }
        if(i1 == word1.length() && j1 != word2.length())
        {
            return word2.length() - j1;
        }
        if(j1 == word2.length() && i1 != word1.length())
        {
            return word1.length() - i1;
        }
        if(word1[i1] == word2[j1])
        {
            return dfs(word1, word2, i1+1, j1+1);
        }
        else
        {
            mp[pr] = min(/* insert*/dfs(word1, word2, i1, j1+1), min(/*delete*/dfs(word1, word2, i1+1, j1), dfs(word1, word2, i1+1, j1+1))) + 1;
            return mp[pr];
        }
    }
};
