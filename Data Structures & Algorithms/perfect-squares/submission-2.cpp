class Solution {
public:
    unordered_map<int,int> mp;
    int numSquares(int n) {
        return minNum(n, 1);
    }
    int minNum(int n, int i)
    {
        if(n == 0)
        {
            return 0;
        }
        if(n == 1 && i == 1)
        {
            return 1;
        }
        if(n < 0 || i > n/2)
        {
            return INT_MAX;
        }
        if(mp.find(n) != mp.end())
        {
            return mp[n];
        }
        int s1 = minNum(n - i*i, i);
        int s2 = minNum(n, i + 1);
        
        if(s1 == INT_MAX)
        {
            mp[n] = s2;
            return s2;
        }
        mp[n] = min(1 + s1, s2);

        return min(1 + s1, s2);

    }
};