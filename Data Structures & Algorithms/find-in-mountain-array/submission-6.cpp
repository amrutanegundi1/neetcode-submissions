/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
   public:
    int findInMountainArray(int target, MountainArray& mountainArr) {
        int l = 1, r = mountainArr.length()-2, peak;
       

        while(l <= r)
        {
             int m = l + (r-l)/2;
             int left = mountainArr.get(m-1), mid = mountainArr.get(m), right =           mountainArr.get(m+1);
             if(left < mid && mid > right)
             {
                peak = m;
                break;
             }
             else if(left < mid && mid < right)
             {
                l = m +1;
             }
             else
             {
                r = m -1;
             }
        }
        l = 0, r = peak;
        while(l <= r)
        {
             int m = l + (r-l)/2;
             int mid = mountainArr.get(m);
             if(mid == target)
             {
                return m;
             }
             else if(target > mid)
             {
                l = m +1;
             }
             else
             {
                r = m -1;
             }
        }

        l = peak + 1, r = mountainArr.length()-1;
        while(l <= r)
        {
             int m = l + (r-l)/2;
             int mid = mountainArr.get(m);
             if(mid == target)
             {
                return m;
             }
             else if(target < mid)
             {
                l = m +1;
             }
             else
             {
                r = m -1;
             }
        }

        return -1;
    }
};