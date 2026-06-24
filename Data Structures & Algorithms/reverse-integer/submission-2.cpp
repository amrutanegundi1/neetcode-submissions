class Solution {
public:
    int reverse(int x) {

        int res = 0, multiplier = 1;
        int MAX_NUM = INT_MAX/10;
        int MIN_NUM = INT_MIN/10;

        while(x != 0)
        {
            if(res > MAX_NUM || res == MAX_NUM && (x%10) > INT_MAX%10)
                return 0;
            if(res < MIN_NUM || res == MIN_NUM && (x%10) < INT_MIN%10)
                return 0;
            res = res*10 + (x%10);
            x = x/10;
        }
        return res;
    }
};
