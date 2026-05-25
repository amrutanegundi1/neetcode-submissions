class Solution {

public:
    int climbStairs(int n) {
        if(n == 0 || n == 1 || n == 2)
            return n;
        int one = 1;
        int two = 2;
        for(int i=3; i <= n; i++)
        {
            int sum = one + two;
            one = two;
            two = sum;
        }
        return two;
    }
};
