class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,int>> deltas;

        for(auto itr : trips)
        {
            deltas.push_back({itr[1], itr[0]});
            deltas.push_back({itr[2], -itr[0]});
        }
        sort(deltas.begin(), deltas.end());
        int currCap = 0;
        for(auto itr : deltas)
        {
            currCap += itr.second;
            if(currCap > capacity)
            {
                return false;
            }
        }
        return true;
    }
};