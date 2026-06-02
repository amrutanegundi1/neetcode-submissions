class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;

        for (int i = 0; i < intervals.size(); i++) {
            // if the new interval is before the curr interval
            if(newInterval[1] < intervals[i][0])
            {
                res.push_back(newInterval);
                for(int j = i; j < intervals.size(); j++)
                {
                    res.push_back(intervals[j]);
                }
                return res;
            }

            //if the new interval is after the current interval
            else if(newInterval[0] > intervals[i][1])
            {
                res.push_back(intervals[i]);
            }
            else
            {
                //its an overlap
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
            
        }
        res.push_back(newInterval);
        return res;
    }
    bool isItBefore(vector<int> curr, vector<int> newInt) {
        int currStart = curr[0], currEnd = curr[1];
        int newStart = newInt[0], newEnd = newInt[1];
        //cout<<"[ "<<currStart<<", "<<currEnd<<" ], [ "<<newStart<<", "<<newEnd<<" ]"<<endl;
        return newEnd < currStart;
    }

    bool isAnOverLap(vector<int> curr, vector<int> newInt) {
        int currStart = curr[0], currEnd = curr[1];
        int newStart = newInt[0], newEnd = newInt[1];
        // cout<<"[ "<<currStart<<", "<<currEnd<<" ], [ "<<newStart<<", "<<newEnd<<" ]"<<endl;
        if ((newStart >= currStart && newStart <= currEnd) || (newEnd >= currStart &&
            newEnd <= currEnd)) {
            // cout<<"true1"<<endl;

            return true;
        }

        if (newStart < currStart && newEnd > currEnd) {
            // cout<<"true2"<<endl;
            return true;
        }
        return false;
    }
};
