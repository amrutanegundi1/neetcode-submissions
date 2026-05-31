class Solution {
public:
    int numDecodings(string s) {
        unordered_map<int,int> mp;
        return numofComb(s,0,mp);
    }

    int numofComb(string s, int i, unordered_map<int,int>& mp)
    {
        if(mp.find(i) != mp.end())
        {
            return mp[i];
        }
        if( i >= s.length())
        {
            return 1;
        }
        if(s[i] == '0')
            return 0;
        
        int res = numofComb(s, i +1, mp);

        if((i+1 < s.length()) && (s[i] == '1' || (s[i] == '2' && s[i+1] >= '0' && s[i+1] <= '6')))
        {
            res += numofComb(s, i +2, mp);
        }
        mp[i] = res;
        return res;
    }
};
