class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x/2;
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            unsigned long pd = (unsigned long)(mid) * mid;
            if(pd == x)
            {
                return mid;
            }
            else if(pd  > x)
            {
                r = mid - 1;
            }
            else
            {
                l = mid +1;
            }
        }
        if(((unsigned long)(l) * l) <= x)
        {
            return l;
        }
        return l-1;
        
    }
};