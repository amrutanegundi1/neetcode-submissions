class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int currMax;
        int res = 0;
        sort(intervals.begin(),intervals.end());
        currMax = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] < currMax)
            {
                currMax = min(currMax, intervals[i][1]);
                res++;
            }
            else
            {
                currMax = max(currMax, intervals[i][1]);
            }
        }
        return res;
    }
};
