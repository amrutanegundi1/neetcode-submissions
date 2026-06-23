class Solution {
public:
    double myPow(double x, int n) {
        double res = binary(x, abs(n));
        if(n < 0)
        {
            return 1 / res;
        }
        return res;
    }

    double binary(double x, int n)
    {
        if(x == 0)
        {
            return 0;
        }
        if(n == 0)
        {
            return 1;
        }
        double res = binary(x, n/2);
        res *= res;
        if(n%2 == 1)
        {
            res = res * x;
        }
        return res;
    }
};
