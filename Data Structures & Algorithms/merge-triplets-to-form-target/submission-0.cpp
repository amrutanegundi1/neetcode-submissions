class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        set<int> res;

        for(int i = 0; i < triplets.size(); i++)
        {
            if(triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2])
                continue;
            if(triplets[i][0] == target[0])
                res.insert(0);
            if(triplets[i][1] == target[1])
                res.insert(1);
            if(triplets[i][2] == target[2])
                res.insert(2);
        }
        return res.size() == 3;
        
    }
};
