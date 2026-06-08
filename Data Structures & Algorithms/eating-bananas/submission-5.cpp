class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = INT_MIN;
        for (auto itr : piles) {
            if(itr > max)
                max = itr;
        }
        int l = 1, r = max;
        cout<<max<<endl;

        int res = INT_MAX;

        while(l <= r)
        {
            int mid = l + (r-l)/2;
            long hr = 0;
            for(auto itr : piles)
                hr += ceil(double(itr)/mid); 
            if(hr <= h)
            {
                if(res > mid)
                    res = mid;
                r = mid-1;
            }
            else if(hr > h)
            {
                l = mid +1;
            }
        }
        return res;
    }
};
