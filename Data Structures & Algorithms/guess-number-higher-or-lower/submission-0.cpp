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
        int pick = INT_MIN;
        while(pick != 0)
        {
            pick = guess(n);
            if(pick == 0)
                return n;
            if(pick < 0)
            {
                n = n + 1;
            }
            else
            {
                n = n -1;
            }
        }
    }
};