class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        unordered_map<int,int> mp;
        for(int i = 0; i < trips.size(); i++)
        {
            for(int j = trips[i][1]; j < trips[i][2]; j++)
            {
                if(mp.find(j) == mp.end())
                {
                    cout<<j<<" "<<capacity - trips[i][0]<<endl;
                    mp[j] = capacity - trips[i][0];
                }
                else
                {
                    mp[j] = mp[j] - trips[i][0];
                }
                if(mp[j] < 0)
                {
                    return false;
                }
            }
        }
        return true;
        
    }
};