class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0;
        while(i < intervals.size())
        {
            if(newInterval[1] < intervals[i][0])
            {
                res.push_back(newInterval);
                //push the rest and return
                for(int j = i; j < intervals.size(); j++)
                {
                    res.push_back(intervals[j]);
                }
                return res;
            }
            else if(newInterval[0] > intervals[i][1])
            {
                res.push_back(intervals[i]);
                i++;
            }
            else
            {
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
                i++;
            }
        }
        res.push_back(newInterval);
        return res;

    }
};
