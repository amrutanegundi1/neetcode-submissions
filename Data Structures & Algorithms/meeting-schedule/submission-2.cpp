/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

 static bool comp(Interval a, Interval b)
 {
    return a.start < b.start;
 }

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        bool res = true;
        sort(intervals.begin(),intervals.end(), comp);
        int prevEnd = intervals[0].end;

        for(int i = 1; i<intervals.size(); i++)
        {
            if(intervals[i].start < prevEnd)
                return false;
            else prevEnd = intervals[i].end; 

        }
        return res;
    
    }
};
