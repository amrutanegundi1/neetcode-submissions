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

class Solution {
public:
    static bool comp(Interval a, Interval b)
    {
        return a.start < b.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(), comp);
        priority_queue<int, vector<int>, greater<int>> heap;

        if(intervals.size() == 0)
            return 0;
        heap.push(intervals[0].end);

        for(int i = 1; i < intervals.size(); i++)
        {
            if(heap.top() > intervals[i].start)
            {
                heap.push(intervals[i].end);
            }
            else
            {
                heap.pop();
                heap.push(intervals[i].end);
            }
        }
        return heap.size();
        
    }
};
