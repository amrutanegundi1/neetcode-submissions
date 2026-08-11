class Solution {
public:
    bool del = false;
    bool validPalindrome(string s) {
        return dfs(s, 0, s.length()-1);
    }

    bool dfs(string s, int l, int r)
    {
        if(l >= r)
        {
            return true;
        }
        if(s[l] == s[r])
        {
            return dfs(s, l+1, r-1);
        }
        else if(del == false)
        {
            del = true;
            return dfs(s, l+1, r) || dfs(s, l, r-1);
        }
        return false;

    }
};