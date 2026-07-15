class CountSquares {
public:
    map<pair<int,int>, int> mp; 
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        pair<int,int> pr = pair<int,int>(point[0], point[1]);
        if(mp.find(pr) != mp.end())
        {
            mp[pr] += 1;
        }
        else
        {
            mp[pr] = 1;
        }
    }
    
    int count(vector<int> point) {
        int res = 0;
        for(auto itr : mp)
        {
            int px = point[0], py = point[1];
            int x = itr.first.first, y = itr.first.second;
            
            if(abs(px-x) == abs(py-y) && ((px != x) && (py != y)))
            {
                if(mp.find(pair<int,int>(x,py)) != mp.end() && mp.find(pair<int,int>(px,y)) != mp.end())
                {
                    res += (mp[pair<int,int>(x,y)] * mp[pair<int,int>(x,py)] * mp[pair<int,int>(px,y)]);
                }
            }
        }
        return res;
    }
};
