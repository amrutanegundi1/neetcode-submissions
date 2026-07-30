class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        vector<int> prev = intervals[0];
        bool added = false;
        int i = 1;
        vector<int> curr;
        while(i < intervals.size()) 
        {
            curr = intervals[i];
            if(curr[0] <= prev[1])
            {
                prev[0] = min(prev[0], curr[0]);
                prev[1] = max(prev[1], curr[1]);
                i++;
            }
            else
            {
                res.push_back(prev);
                prev =curr;
                i++;
            }
        }
        res.push_back(prev);
        return res;

    }
};
