class Solution {
public:
    bool canJump(vector<int>& nums) {
        int pos = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            if(pos >= i)
                pos = max(pos, i + nums[i]);
        }
        if(pos >= nums.size()-1)
            return true;
        return false;
    }
};
