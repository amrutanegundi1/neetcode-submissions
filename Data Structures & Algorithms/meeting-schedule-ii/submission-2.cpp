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
    static bool comp(const Interval &a, const Interval &b)
    {
        return a.start < b.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> rooms; 
        if(intervals.size() == 0)
            return 0;
        sort(intervals.begin(), intervals.end(), comp);
        rooms.push_back(intervals[0].end);
        cout<<rooms[0]<<endl;
        for(int i = 1; i < intervals.size(); i++)
        {
            bool roomFound = false;
            for(int j = 0; j < rooms.size(); j++)
            {
                if(rooms[j] <= intervals[i].start)
                {
                    roomFound = true;
                    rooms[j] = intervals[i].end;
                    cout<<j<<" "<<rooms[j]<<endl;
                    break;
                }
            }
            if(!roomFound)
            {
                rooms.push_back(intervals[i].end);
                cout<<rooms.size()-1<<" "<<rooms[rooms.size()-1]<<endl;
            }
        }
        return rooms.size();
        
    }
};
