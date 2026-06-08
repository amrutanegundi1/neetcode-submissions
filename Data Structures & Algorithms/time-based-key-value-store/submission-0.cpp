class TimeMap {
public:
    unordered_map<string, vector<pair<string,int>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        string result = "";
        if(mp.find(key) != mp.end())
        {
            int currtime = INT_MIN;
            vector<pair<string,int>> vt = mp[key];
            for(auto itr : vt)
            {
                if(itr.second <= timestamp && itr.second > currtime)
                {
                    result = itr.first;
                    currtime = itr.second;
                }
            }
        }
        return result;
    }
};
