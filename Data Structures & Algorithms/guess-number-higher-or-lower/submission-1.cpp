/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 0, r = n, pick = -1;
        while(pick != 0)
        {
            int mid = l +(r-l)/2;
            pick = guess(mid);
            if(pick == 0)
                return mid;
            if(pick < 0)
            {
                l = mid + 1;
            }
            else
            {
                r = mid -1;
            }
        }
    }
};