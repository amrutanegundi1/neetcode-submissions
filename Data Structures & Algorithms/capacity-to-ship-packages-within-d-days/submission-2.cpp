class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        int minWeight = INT_MIN, maxWeight = 0;
        for(auto itr : weights)
        {
            if(itr > minWeight)
            {
                minWeight = itr;
            }
            maxWeight += itr;
        }
        int l = minWeight, r = maxWeight, res, counter = 5;
        while(l <= r)
        {
            counter--;
            int mid = l + (r-l)/2;
            int num = noOfDays(weights, mid);
            if(num <= days)
            {
                res = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return res;
    }
    int noOfDays(vector<int>& weights, int maxWeight)
    {
        int temp = 0, count = 0;
        for(auto itr : weights)
        {
            if(temp + itr <= maxWeight)
            {
                temp += itr;
            }
            else
            {
                count++;
                temp = itr;
            }
        }
        if(temp > 0)
        {
            count += 1;
        }
        return count;
    }
};