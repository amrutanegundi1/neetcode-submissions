class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long sum = 0;
        for (auto itr : piles) {
            sum += itr;
        }

        if (h > sum) {
            return 1;
        }

        int res = 1;
        long hr = 0;
        do {
            res++;
            hr = 0;
            for (auto itr : piles) {
                hr += ceil(double(itr)/res);
            }
        } while (hr > h);
        return res;
    }
};
