class Solution {
public:
    long long minEnd(int n, int x) {

        long long res = x;

        for(int i = 0; i < n-1; i++)
        {
            res = res + 1;
            res = res | x;
        }
        return res;
    }
};