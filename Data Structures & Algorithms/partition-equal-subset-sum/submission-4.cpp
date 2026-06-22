class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(auto itr : nums)
        {
            total += itr;
        }
        if(total % 2 != 0)
        {
            return false;
        }
        total = total/2;
        set<int> s;
        s.insert(0);
        for(int i = 0; i < nums.size(); i++)
        {
            set<int> temp = s;
            for(auto itr : s)
            {
                temp.insert(itr + nums[i]);
            }
            s = temp;
        }
        if(s.find(total) != s.end())
            return true;
        return false;
    }
};
