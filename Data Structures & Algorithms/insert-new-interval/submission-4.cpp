class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        vector<int> intToAdd;
        bool merged = false, processed = false;
        for (int i = 0; i < intervals.size(); i++) {
            if (merged) {
                if (intToAdd[1] > intervals[i][1]) {
                    // cout<<"continue"<<endl;
                    continue;
                }
                else if (isAnOverLap(intToAdd, intervals[i])) {
                    intToAdd[0] = min(res[res.size()-1][0], min(intervals[i][0], intToAdd[0]));
                    intToAdd[1] = max(intervals[i][1], intToAdd[1]);
                    res[res.size() - 1] = intToAdd;
                } else {
                    res.push_back(intervals[i]);
                }

            } else {
                if (!processed && isItBefore(intervals[i], newInterval)) {
                    processed = true;
                    res.push_back(newInterval);
                    res.push_back(intervals[i]);
                } else if (isAnOverLap(intervals[i], newInterval)) {
                    intToAdd.push_back(min(intervals[i][0], newInterval[0]));
                    intToAdd.push_back(max(intervals[i][1], newInterval[1]));
                    res.push_back(intToAdd);
                    merged = true;
                } else {
                    res.push_back(intervals[i]);
                }
            }
        }
        if(!processed && !merged)
        {
            res.push_back(newInterval);
        }
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
