class Solution {

public:
    int climbStairs(int n) {
        if(n == 0 || n == 1 || n == 2)
            return n;
        std::vector<int> counter(n+1,0);
        counter[0] = 0;
        counter[1] = 1;
        counter[2] = 2;
        for(int i=3; i <= n; i++)
        {
            counter[i] = counter[i-1] + counter[i-2];
        }
        return counter[n];
    }
};
