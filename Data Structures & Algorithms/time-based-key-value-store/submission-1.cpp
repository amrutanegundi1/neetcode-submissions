class TimeMap {
public:
    unordered_map<string, vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        string result = "";
        vector<pair<int,string>> search = mp[key];
        int l = 0, r = search.size()-1;

        while(l <= r)
        {
            int m = l + (r-l)/2;

            if(search[m].first <= timestamp)
            {
                result = search[m].second;
                l = m + 1;
            }
            else
            {
                r = m -1;
            }
        } 
        return result;
    }
};
